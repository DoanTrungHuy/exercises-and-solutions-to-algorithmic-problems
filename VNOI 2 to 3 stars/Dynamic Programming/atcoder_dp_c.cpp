#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N;
const ll MN = 1e5 + 10;
ll memo[MN][4];
ll a[MN][3];

ll dp(ll i, ll state) {
    if (i == N) {
        return 0;
    }
    if (memo[i][state] != -1) {
        return memo[i][state];
    }
    ll ans = 0;
    for (ll j = 0; j < 3; ++j) {
        if (j != state) {
            ans = max(ans, a[i][j] + dp(i + 1, j));
        }
    }
    return memo[i][state] = ans;
}

int main() {
    cin >> N;
    for (ll i = 0; i < N; ++i) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 3);
    return 0;
}