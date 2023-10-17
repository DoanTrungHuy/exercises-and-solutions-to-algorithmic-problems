#include <bits/stdc++.h>

using namespace std;

using ll = long long;
ll N, M;
const ll MN = 2e5 + 1;
vector<ll> adj[MN];
ll depth[MN], original_parent[MN];

void dfs(ll u, ll p) {
    for (ll v : adj[u]) {
        if (v == p) {
            continue;
        }
        original_parent[v] = u;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

ll parent[MN];

ll find(ll u) {
    if (u != parent[u]) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

ll del_edge = 0;

void lca(ll u, ll v) {
    while (u != v) {
        u = find(u);
        v = find(v);

        if (u == v) {
            break;
        }

        ll du = depth[u];
        ll dv = depth[v];

        if (du <= dv) {
            v = parent[v] = original_parent[v];
            del_edge++;
        }
        if (dv <= du) {
            u = parent[u] = original_parent[u];
            del_edge++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cin >> N;
    for (ll i = 1; i <= N - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(depth, 0, sizeof(depth));
    dfs(1, -1);
    cin >> M;
    for (ll i = 1; i <= N; ++i) {
        parent[i] = i;
    }
    for (ll i = 1; i <= M; ++i) {
        ll u, v;
        cin >> u >> v;
        lca(u, v);
    }
    cout << N - 1 - del_edge;
    return 0;
}