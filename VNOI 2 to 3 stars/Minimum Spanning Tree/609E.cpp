#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, M;
using tp = tuple<ll, ll, ll, ll>;
vector<tp> edges;
const ll MN = 2e5 + 1;
using pr = pair<ll, ll>;
vector<pr> adj[MN];

class DSU {
private:
    vector<ll> parent;

public:
    DSU(ll n = 0) {
        parent.resize(n + 1);
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
        parent[u] = v;
        return true;
    }
};

ll total_cost_min() {
    sort(edges.begin(), edges.end(), [&](const tp &a, const tp &b) {
        return get<2>(a) < get<2>(b);
    });

    ll total = 0;
    DSU dsu(N);

    for (ll i = 0; i < M; ++i) {
        auto [u, v, w, id] = edges[i];
        if (!dsu._union(u, v)) {
            continue;
        }
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        total += w;
    }

    return total;
}

struct Data {
    ll par, mxp;

    Data(ll par = -1, ll mxp = INT_MIN) {
        this->par = par;
        this->mxp = mxp;
    }
};

const ll LOG = ceil(log2(MN));
Data up[MN][LOG + 1];
ll depth[MN];

void dfs(ll u, ll p) {
    for (const auto &[v, w] : adj[u]) {
        if (v == p) {
            continue;
        }
        up[v][0].par = u;
        up[v][0].mxp = w;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

ll get_max_edge(ll u, ll v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    ll diff = depth[u] - depth[v];

    ll max_edge = INT_MIN;

    for (ll i = LOG; i >= 0; --i) {
        if (diff & (1 << i)) {
            max_edge = max(max_edge, up[u][i].mxp);
            u = up[u][i].par;
        }
    }

    if (u == v) {
        return max_edge;
    }

    for (ll i = LOG; i >= 0; --i) {
        if (up[u][i].par != up[v][i].par) {
            max_edge = max({max_edge, up[u][i].mxp, up[v][i].mxp});
            u = up[u][i].par;
            v = up[v][i].par;
        }
    }

    return max({max_edge, up[u][0].mxp, up[v][0].mxp});
}

int main() {
    cin >> N >> M;
    for (ll i = 0; i < M; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w, i});
    } 
    ll total = total_cost_min();
    memset(up, -1, sizeof(up));
    dfs(1, -1);
    for (ll j = 1; j <= LOG; ++j) {
        for (ll u = 1; u <= N; ++u) {
            if (up[u][j - 1].par != -1) {
                up[u][j].par = up[up[u][j - 1].par][j - 1].par;
                up[u][j].mxp = max(up[u][j - 1].mxp, up[up[u][j - 1].par][j - 1].mxp);
            }
        }
    }
    ll res[M];
    for (ll i = 0; i < M; ++i) {
        const auto [u, v, w, id] = edges[i];
        res[id] = total - get_max_edge(u, v) + w;
    }
    for (ll i = 0; i < M; ++i) {
        cout << res[i] << '\n';
    }
    return 0;
}