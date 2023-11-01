#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, M, K;
const ll MN = 2e5 + 1;

struct DSU {
    vector<ll> parent;
    vector<ll> rank;

    DSU(ll n = 0) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (ll i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    ll find(ll u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool _union(ll u, ll v) {
        u = find(u);
        v = find(v);

        if (u == v) {
            return false;
        }

        if (rank[u] < rank[v]) {
            swap(u, v);
        }

        parent[v] = u;
        rank[u] += rank[v];

        return true;
    }
};

using pii = pair<ll, ll>;
vector<pii> adj[MN];

struct Node {
    ll par, mxm;

    Node(ll par = -1, ll mxm = 0) {
        this->par = par;
        this->mxm = mxm;
    }
};

bool visited[MN];
const ll LOG = ceil(log2(MN));
Node up[MN][LOG + 1];
ll depth[MN];

void dfs(ll u, ll p) {
    visited[u] = true;
    for (const auto &[v, w] : adj[u]) {
        if (v == p) {
            continue;
        }
        up[v][0].par = u;
        up[v][0].mxm = w;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

ll max_time(ll u, ll v) {
    ll max_u = 0, max_v = 0;

    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    ll diff = depth[u] - depth[v];

    for (ll i = LOG; i >= 0; --i) {
        if (diff & (1 << i)) {
            max_u = max(max_u, up[u][i].mxm);
            u = up[u][i].par;
        }
    }

    if (u == v) {
        return max_u;
    }

    for (ll i = LOG; i >= 0; --i) {
        if (up[u][i].par != up[v][i].par) {
            max_u = max(max_u, up[u][i].mxm);
            max_v = max(max_v, up[v][i].mxm);
            u = up[u][i].par;
            v = up[v][i].par;
        }
    }

    return max({
        max_u,
        max_v,
        up[u][0].mxm,
        up[v][0].mxm
    });
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    DSU dsu(N);
    for (ll i = 1; i <= M; ++i) {
        ll u, v;
        cin >> u >> v;
        if (dsu._union(u, v)) {
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
    }
    memset(visited, false, sizeof(visited));
    memset(depth, 0, sizeof(depth));
    for (ll i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }
    for (ll j = 1; j <= LOG; ++j) {
        for (ll i = 1; i <= N; ++i) {
            if (up[i][j - 1].par != -1) {
                up[i][j].mxm = max(up[i][j - 1].mxm, up[up[i][j - 1].par][j - 1].mxm);
                up[i][j].par = up[up[i][j - 1].par][j - 1].par;
            }
        }
    }
    while (K--) {
        ll u, v;
        cin >> u >> v;
        if (dsu.find(u) != dsu.find(v)) {
            cout << -1 << '\n';
        }
        else {
            cout << max_time(u, v) << '\n';
        }
    }
    return 0;
}