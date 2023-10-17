#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, M;
const ll MN = 801;
vector<ll> adj[MN];
ll num[MN], low[MN];
ll id_node = 0;
stack<ll> st;
bool del[MN];
ll scc = 0;
ll mp_component[MN];

void dfs(ll u) {
    st.push(u);
    num[u] = low[u] = ++id_node;
    for (ll v : adj[u]) {
        if (del[v]) {
            continue;
        }
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        }
        else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (num[u] == low[u]) {
        ++scc;
        ll t;
        do {
            t = st.top();
            st.pop();
            mp_component[t] = scc;
            del[t] = true;
        } while (t != u);
    }
}

int main() {
    cin >> N >> M;
    for (ll i = 0; i < M; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (ll i = 1; i <= N; ++i) {
        if (num[i] == 0) {
            dfs(i);
        }
    }
    ll indegree[MN] = {};
    for (ll u = 1; u <= N; ++u) {
        for (ll v : adj[u]) {
            if (mp_component[u] != mp_component[v]) {
                indegree[mp_component[v]]++;
            }
        }
    }
    ll cnt_connect_edge = 0;
    for (ll i = 1; i <= scc; ++i) {
        cnt_connect_edge += indegree[i] > 0;
    }
    cout << scc - cnt_connect_edge;
    return 0;
}