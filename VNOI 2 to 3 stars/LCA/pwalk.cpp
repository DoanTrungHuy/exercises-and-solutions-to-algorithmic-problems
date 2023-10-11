#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MN = 1e5 + 1;
ll n, m;
using pr = pair<ll, ll>;
vector<pr> adj[MN];
vector<vector<ll>> par;
ll depth[MN], sum[MN];
ll LOG;

void dfs(ll u, ll p) {
    par[u][0] = p;
    for (const auto [v, w] : adj[u]) {
        if (v == p) {
            continue;
        }
        depth[v] = depth[u] + 1;
        sum[v] = w + sum[u];
        dfs(v, u);
    }
}

ll node_lca(ll u, ll v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    ll diff = depth[u] - depth[v];
    for (ll i = LOG; i >= 0; --i) {
        if (diff & (1 << i)) {
            u = par[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (ll i = LOG; i >= 0; --i) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int main() {
    cin >> n >> m;
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    LOG = ceil(log2(n));
    par.resize(n + 1, vector<ll>(LOG + 1, -1));
    memset(sum, 0, sizeof(sum));
    memset(depth, 0, sizeof(depth));
    dfs(1, -1);
    for (ll j = 1; j <= LOG; ++j) {
        for (ll i = 1; i <= n; ++i) {
            if (par[i][j - 1] != -1) {
                par[i][j] = par[par[i][j - 1]][j - 1];
            }
        }
    }
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        cout << sum[u] + sum[v] - 2*sum[node_lca(u, v)] << '\n';
    }
    return 0;
}