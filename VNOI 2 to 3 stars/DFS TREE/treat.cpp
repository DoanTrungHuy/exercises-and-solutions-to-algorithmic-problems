#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, M;
const ll MN = 1e5 + 1;
vector<ll> adj[MN];
ll num[MN], low[MN];
ll id_node = 0;
stack<ll> st;
bool del[MN];
ll scc = 0;
ll mapping_connected[MN], size_in_connected[MN];

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
        ll t;
        ++scc;
        do {
            t = st.top();
            st.pop();
            del[t] = true;
            mapping_connected[t] = scc;
            size_in_connected[scc]++;
        } while (t != u);
    }
}

map<int, set<int>> mpc_adj;
ll indegree[MN], memo[MN];

ll dag_dfs(ll u) {
    if (memo[u] != -1) {
        return memo[u];
    }
    ll ans = size_in_connected[u];
    for (ll v : mpc_adj[u]) {
        dag_dfs(v);
        ans += memo[v];
    }
    return memo[u] = ans;
}

int main() {
    cin >> N;
    for (ll i = 1; i <= N; ++i) {
        ll next_i;
        cin >> next_i;
        adj[i].push_back(next_i);
    }
    for (ll u = 1; u <= N; ++u) {
        if (num[u] == 0) {
            dfs(u);
        }
    }
    for (ll u = 1; u <= N; ++u) {
        for (ll v : adj[u]) {
            if (mapping_connected[u] != mapping_connected[v]) {
                mpc_adj[mapping_connected[u]].insert(mapping_connected[v]);
                indegree[mapping_connected[v]]++;
            }
        }
    }
    memset(memo, -1, sizeof(memo));
    for (ll u = 1; u <= scc; ++u) {
        if (indegree[u] == 0) {
            dag_dfs(u);
        }
    }
    for (ll u = 1; u <= N; ++u) {
        cout << memo[mapping_connected[u]] << '\n';
    }
    return 0;
}