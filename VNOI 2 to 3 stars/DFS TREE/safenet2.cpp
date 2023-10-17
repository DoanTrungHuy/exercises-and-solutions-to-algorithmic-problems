#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, M;
const ll MN = 30001;
vector<ll> adj[MN];
ll num[MN], low[MN];
ll id_node = 0;
stack<pair<ll, ll>> st;
ll res = 0;
ll del[MN];

void dfs(ll u, ll p) {
    num[u] = low[u] = ++id_node;
    for (ll v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (del[v]) {
            continue;
        }
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        }
        else {
            st.push({u, v});
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[u]) {
                pair<ll, ll> t = {-1, -1};
                pair<ll, ll> o = {u, v};
                ll cnt = 1;
                do {
                    t = st.top();
                    st.pop();
                    del[t.second] = 1; 
                    cnt++;
                } while (t != o);
                res = max(res, cnt);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (ll i = 0; i < M; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (ll i = 1; i <= N; ++i) {
        if (num[i] == 0) {
            dfs(i, -1);
        }
    }
    cout << max(1LL, res);
    return 0;
}