#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MN = 1005;
ll N, M;
vector<ll> adj[MN];

struct DSU {
    ll parent[MN];

    DSU() {
        for (ll i = 0; i <= 1000; ++i) {
            parent[i] = i;
        }
    }

    ll find(ll u) {
        if (parent[u] != u) {
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

    void init() {
        for (ll i = 0; i <= 1000; ++i) {
            parent[i] = i;
        }
    }
};

DSU dsu;

void dfs_mst(ll u) {
    for (ll v : adj[u]) {
        if (dsu._union(u, v)) {
            cout << u << ' ' << v << '\n';
            dfs_mst(v);
        }
    }
}

ll num[MN], low[MN];
ll id_node = 0;
stack<ll> st;
ll scc = 0;
ll del[MN];
ll mapping_connected[MN], size_of_connected[MN];

void dfs(ll u, ll p) {
    st.push(u);
    num[u] = low[u] = ++id_node;
    for (ll v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (del[v]) {
            continue;
        }
        if (num[v]) {
            low[u] = min(low[u], low[v]);
        }
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
    }
    if (num[u] == low[u]) {
        ll t;
        scc++;
        do {
            t = st.top();
            st.pop();
            del[t] = 1;
            mapping_connected[t] = scc;
            size_of_connected[scc]++;
        } while (t != u);
    }
}

int main() {
    cin >> N >> M;
    for (ll i = 1; i <= M; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    cout << 3 << '\n';
    for (ll i = 1, j = 0; i <= N and j < 3; ++i) {
        if (size_of_connected[mapping_connected[i]] >= 3) {
            dfs_mst(i);
            dsu.init();
            j++;
        }
    }
    return 0;
}