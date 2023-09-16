#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
ll n, m;
const ll MN = 16, MM = 1e4;
ll grid[MN][MM];
ll cost[2][MN][MN];
const ll INF = 1e18;
ll memo[1 << MN][MN];
 
ll dp(ll mask, ll u, ll end) {
    if (__builtin_popcountll(mask) == n) {
        return INF;
    }
    else if (u == end) {
        return 0;
    }
    if (memo[mask][u] != -1) {
        return memo[mask][u];
    }
    ll ans = 0;
    for (ll v = 0; v < n; ++v) {
        if (!(mask & (1 << v))) {
            ans = max(ans, min(cost[0][u][v], dp(mask ^ (1 << v), v, end)));
        }
    }
    return memo[mask][u] = ans;
}
 
int main() {
    cin >> n >> m;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cost[0][i][j] = INF;
            for (ll k = 0; k < m; ++k) {
                cost[0][i][j] = min(cost[0][i][j], abs(grid[i][k] - grid[j][k]));
            }
            cost[1][i][j] = INF;
            for (ll k = 0; k < m - 1; ++k) {
                cost[1][i][j] = min(cost[1][i][j], abs(grid[i][k + 1] - grid[j][k]));
            }
        }
    }
    ll ans = -INF;
    for (ll i = 0; i < n; ++i) {
        memset(memo, -1, sizeof(memo));
        for (ll j = 0; j < n; ++j) {
            ans = max(ans, min(cost[1][i][j], dp(1 << j, j, i)));
        }
    }
    cout << ans;
	return 0;
}