#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, W;
const ll MW = 1e5 + 1;
const ll MN = 100;
ll w[MN], v[MN];
ll memo[MN][MW];

ll dp(ll i, ll s) {
    if (i == N) {
        if (s <= W) {
            return 0;
        }
        return LLONG_MIN;
    }
    if (s > W) {
        return LLONG_MIN;
    }
    if (memo[i][s] != -1) {
        return memo[i][s];
    }
    return memo[i][s] = max({
        dp(i + 1, s),
        v[i] + dp(i + 1, s + w[i])
    });
}

int main() {
    cin >> N >> W;
    for (ll i = 0; i < N; ++i) {
        cin >> w[i] >> v[i];
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0);
    return 0;
}