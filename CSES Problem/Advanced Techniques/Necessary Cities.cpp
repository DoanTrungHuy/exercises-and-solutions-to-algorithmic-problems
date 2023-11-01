#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, M;
const ll MN = 1e5 + 1;
ll num[MN], low[MN];
ll id_node = 0;
vector<ll> adj[MN];
set<ll> ans;

void dfs(ll u, ll p) {
    num[u] = low[u] = ++id_node;
    ll cnt_child = 0;
    for (ll v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        }
        else {
            dfs(v, u);
            cnt_child++;
            low[u] = min(low[u], low[v]);
            if (p == u and cnt_child > 1) {
                ans.insert(u);
            }
            else if (p != u and num[u] <= low[v]) {
                ans.insert(u);
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
    dfs(1, 1);
    cout << ans.size() << '\n';
    for (const auto v : ans) {
        cout << v << ' ';
    }
    return 0;
}