#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, M;
const ll MN = 1e4 + 5;
vector<ll> adj[MN];
ll num[MN], low[MN];
ll id_node = 0;
ll res = 0;
stack<ll> st;
bool del[MN];

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
        do {
            t = st.top();
            st.pop();
            del[t] = true;
        } while (t != u);
        res++;
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
    cout << res;
    return 0;
}