#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
ll n, m, T;
const ll MN = 5000;
vector<pair<ll, ll>> rev_adj[MN];
int memo[MN][MN];
int par[MN][MN];
const ll INF = 2e9;
 
ll dp(ll v, ll len) {
    if (len == 0) {
        if (v == 0) {
            return 0;
        }
        return INF;
    }
    if (memo[v][len] != -1) {
        return memo[v][len];
    }
    ll best = INF;
    for (const auto [u, t] : rev_adj[v]) {
        ll val = dp(u, len - 1) + t;
        if (val < best) {
            best = val;
            par[v][len] = u;
        }
    }
    return memo[v][len] = best;
}
 
int main() {
    cin >> n >> m >> T;
    for (ll i = 0; i < m; ++i) {
        ll u, v, t;
        cin >> u >> v >> t;
        u--;
        v--;
        rev_adj[v].push_back({u, t});
    }
    memset(memo, -1, sizeof(memo));
    memset(par, 0, sizeof(par));
    ll longest_path = 0;
    for (ll len = 0; len < n; ++len) {
        ll val = dp(n - 1, len);
        if (val <= T) {
            longest_path = len;
        }
    }
    cout << longest_path + 1 << '\n';
    ll u = n - 1;
    ll curr_path = longest_path;
    vector<ll> path;
    while (u != 0) {
        path.push_back(u);
        u = par[u][curr_path];
        curr_path--;
    }
    path.push_back(0);
    reverse(path.begin(), path.end());
    for (ll u : path) {
        cout << u + 1 << ' ';
    }
	return 0;
}