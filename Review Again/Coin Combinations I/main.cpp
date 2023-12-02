#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N, X;
const ll MN = 1e6 + 100;
ll a[MN];
const ll MOD = 1e9 + 7;
ll memo[MN];

ll dp(ll s) {
    if (s == 0) {
        return 1;
    }
    if (s < 0) {
        return 0;
    }
    if (memo[s] != -1) {
        return memo[s];
    }
    ll ans = 0;
    for (ll i = 0; i < N; ++i) {
        (ans += dp(s - a[i])) %= MOD;
    }
    return memo[s] = ans;
}

int main() {
    cin >> N >> X;
    for (ll i = 0; i < N; ++i) {
        cin >> a[i];
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(X);
    return 0;
}
