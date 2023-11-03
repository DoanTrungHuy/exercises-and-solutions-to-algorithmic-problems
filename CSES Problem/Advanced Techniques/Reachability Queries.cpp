#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, M, Q;
const ll MN = 5e4 + 10;
vector<ll> adj[MN];
ll num[MN], low[MN], del[MN];
ll id_node = 0, id_scc = 0;
ll mapping_connected[MN];
stack<ll> st;

void dfs(ll u) {
    num[u] = low[u] = ++id_node;
    st.push(u);
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
        ++id_scc;
        do {
            t = st.top();
            st.pop();
            del[t] = 1;
            mapping_connected[t] = id_scc;
        } while (t != u);
    }
}

vector<ll> adj_dag[MN];
bitset<MN> dp[MN];
ll indegree[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> Q;
    for (ll i = 1; i <= M; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (ll i = 1; i <= N; ++i) {
        if (num[i] == 0) {
            dfs(i);
        }
    }
    for (ll u = 1; u <= N; ++u) {
        for (ll v : adj[u]) {
            if (mapping_connected[v] ^ mapping_connected[u]) {
                adj_dag[mapping_connected[v]].push_back(mapping_connected[u]);
                indegree[mapping_connected[u]]++;
            }
        }
        dp[mapping_connected[u]][u] = 1;
    }
    queue<ll> mq;
    for (ll i = 1; i <= id_scc; ++i) {
        if (indegree[i] == 0) {
            mq.push(i);
        }
    }
    while (!mq.empty()) {
        ll u = mq.front();
        mq.pop();

        for (ll v : adj_dag[u]) {
            dp[v] |= dp[u];
            if (--indegree[v] == 0) {
                mq.push(v);
            }
        }
    }
    while (Q--) {
        ll a, b;
        cin >> a >> b;
        cout << (dp[mapping_connected[a]][b] ? "YES" : "NO") << '\n';
    }
    return 0;
}