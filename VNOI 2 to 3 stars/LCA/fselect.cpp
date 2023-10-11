#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, k;
const ll MN = 2e5 + 1;
vector<ll> adj[MN], groups[MN];
ll depth[MN];
vector<vector<ll>> par;
ll LOG;

void dfs(ll u, ll p) {
    par[u][0] = p;
    for (ll v : adj[u]) {
        if (v == p) {
            continue;
        }
        depth[v] = depth[u] + 1;
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

ll calc_dist(ll u, ll v) {
    return depth[u] + depth[v] - 2*depth[node_lca(u, v)];
}

ll max_dist(vector<ll> &group) {
    ll max_dist = INT_MIN;
    ll dummy_node = group[0];
    ll node_max_dist = group[0];

    for (ll member : group) {
        ll dist = calc_dist(dummy_node, member);
        if (dist > max_dist) {
            max_dist = dist;
            node_max_dist = member;
        }
    }

    for (ll member : group) {
        max_dist = max(max_dist, calc_dist(node_max_dist, member));
    }

    return max_dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    ll root = 0;
    for (ll i = 1; i <= n; ++i) {
        ll x, y;
        cin >> x >> y;
        if (y == 0) {
            root = i;
        }
        groups[x].push_back(i);
        adj[i].push_back(y);
        adj[y].push_back(i);
    }
    LOG = ceil(log2(n));
    par.resize(n + 1, vector<ll>(LOG + 1, -1));
    memset(depth, -1, sizeof(depth));
    dfs(root, -1);
    for (ll j = 1; j <= LOG; ++j) {
        for (ll i = 1; i <= n; ++i) {
            if (par[i][j - 1] != -1) {
                par[i][j] = par[par[i][j - 1]][j - 1];
            }
        }
    }
    for (ll i = 1; i <= k; ++i) {
        cout << max_dist(groups[i]) << '\n';
    }
    return 0;
}