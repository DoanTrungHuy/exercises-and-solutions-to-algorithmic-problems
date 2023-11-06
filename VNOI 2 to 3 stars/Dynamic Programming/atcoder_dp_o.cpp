#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MN = 22;
ll N;
ll a[MN][MN];
ll memo[MN][1 << MN];
const ll MOD = 1e9 + 7;

ll dp(ll i, ll mask) {
    if (i == N) {
        return 1;
    }
    if (memo[i][mask] != -1) {
        return memo[i][mask];
    }
    ll ans = 0;
    for (ll j = 0; j < N; ++j) {
        if (a[i][j] == 1 and ((mask & (1 << j)) == 0)) {
            ans = (ans + dp(i + 1, mask | (1 << j))) % MOD;
        }
    }
    return memo[i][mask] = ans;
}

int main() {
    cin >> N;
    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0);
    return 0;
}