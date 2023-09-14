#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, k;
const ll MN = 2e3 + 1;
ll cnt[MN];
const ll MOD = 1e9 + 7;

ll memo[MN][MN];

ll dp(ll i, ll j) {
    if (i == k) {
        return 1;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    ll ans = dp(i + 1, j);
    for (ll v = 2*j; v <= n; v += j) {
        ans = (ans + dp(i + 1, v)) % MOD;
    }
    return memo[i][j] = ans;
}

int main() {
    cin >> n >> k;
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 1);
	return 0;
}