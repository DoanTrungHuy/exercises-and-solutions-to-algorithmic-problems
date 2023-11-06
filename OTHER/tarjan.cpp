#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MN = 5e4 + 10;
vector<ll> adj[MN];
ll N, M;
ll num[MN], low[MN];
ll id_node = 0;
stack<ll> st;
ll id_scc = 0;
ll mapping_connected[MN];
ll del[MN];

void dfs(ll u, ll p) {
    st.push(u);
    num[u] = low[u] = ++id_node;
    for (ll v : adj[u]) {
        if (v == p or del[v]) {
            continue;
        }

        if (num[v] == 0) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
        else {
            low[u] = min(low[u], num[v]);
        }
    }
    if (num[u] == low[u]) {
        ll t;
        id_scc++;
        do {
            t = st.top();
            st.pop();
            mapping_connected[t] = id_scc;
            del[t] = 1;
        } while (t != u);
    }
}

int main() {
    cin >> N >> M;
    for (ll i = 1; i <= M; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (ll i = 1; i <= N; ++i) {
        if (num[i] == 0) {
            dfs(i, i);
        }
    }
    for (ll i = 1; i <= N; ++i) {
        cout << mapping_connected[i] << ' ';
    }
    // vector<ll> adj_dag[MN];
    // for (ll u = 1; u <= N; ++u) {
    //     for (ll v : adj[u]) {
    //         if (mapping_connected[u] != mapping_connected[v]) {
    //             adj_dag[mapping_connected[u]].push_back(mapping_connected[v]);
    //         }
    //     }
    // }
    // //... Topo Sort
    return 0;
}