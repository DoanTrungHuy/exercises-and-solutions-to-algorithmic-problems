#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, W;
const ll MV = 1e5 + 1;
const ll MN = 100;
ll w[MN], v[MN];
ll memo[MN][MV];
const ll oo = 1e18;

ll dp(ll i, ll s) {
    if (i == N or s == 0) {
        return (s != 0 ? oo : 0);
    }
    if (s < 0) {
        return oo;
    }
    if (memo[i][s] != -1) {
        return memo[i][s];
    }
    return memo[i][s] = min({
        dp(i + 1, s),
        w[i] + dp(i + 1, s - v[i])
    });
}

int main() {
    cin >> N >> W;
    ll s = 0;
    for (ll i = 0; i < N; ++i) {
        cin >> w[i] >> v[i];
        s += v[i];
    }
    memset(memo, -1, sizeof(memo));
    dp(0, 0);
    for (ll i = s; i >= 0; --i) {
        if (dp(0, i) <= W) {
            cout << i;
            break;
        }
    }
    return 0;
}