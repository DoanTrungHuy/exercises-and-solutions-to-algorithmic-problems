#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N;
const ll MN = 1e6 + 100;
ll a[MN];
ll memo[MN];
const ll MOD = 1e9 + 7;

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
    for (ll i = 1; i <= 6; ++i) {
        (ans += dp(s - i)) %= MOD;
    }
    return memo[s] = ans;
}

int main() {
    cin >> N;
    memset(memo, -1, sizeof(memo));
    cout << dp(N);
    return 0;
}
