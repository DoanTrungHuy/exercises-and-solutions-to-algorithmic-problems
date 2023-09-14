#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n;
const ll MN = 3002;
ll s[MN], c[MN];
const ll MT = 3;
ll memo[MN][MN][MT];
const ll INF = 1e18;

ll dp(ll i, ll j, ll k) {
    if (k == MT) {
        return 0;
    }
    if (i == n) {
        return INF;
    }
    if (memo[i][j + 1][k] != -1) {
        return memo[i][j + 1][k];
    }
    ll ans = dp(i + 1, j, k);
    if (j == -1 or s[j] < s[i]) {
        ans = min(ans, c[i] + dp(i + 1, i, k + 1));
    }
    return memo[i][j + 1][k] = ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    memset(memo, -1, sizeof(memo));
    ll ans = dp(0, -1, 0);
    cout << (ans == INF ? -1 : ans);
	return 0;
}