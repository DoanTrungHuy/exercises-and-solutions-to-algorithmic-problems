#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m;
const ll MN = 1e4 + 1;
vector<ll> adj[MN];
ll articulation_point, bridge;
ll num[MN], low[MN];
ll id_node = 0;

void dfs(ll u, ll p) {
    num[u] = low[u] = ++id_node;
    ll node = p != -1;
    for (ll v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        }
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v]) {
                bridge++;
            }
            if (low[v] >= num[u]) {
                node++;
            }
        }
    }
    if (node >= 2) {
        articulation_point++;
    }
}

int main() {
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (ll i = 1; i <= n; ++i) {
        if (num[i] == 0) {
            dfs(i, -1);
        }
    }
    cout << articulation_point << ' ' << bridge;
    return 0;
}