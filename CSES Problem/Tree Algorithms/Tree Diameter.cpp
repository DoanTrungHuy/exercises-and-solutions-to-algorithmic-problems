#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N;
const ll MN = 2e5 + 2;
vector<ll> adj[MN];
ll node_max_depth = 1, max_depth = 0;

void dfs(ll u, ll p, ll depth) {
    for (ll v : adj[u]) {
        if (v != p) {
            dfs(v, u, depth + 1);
        }
    }
    if (depth > max_depth) {
        max_depth = depth;
        node_max_depth = u;
    }
}

int main() {
    cin >> N;
    for (ll i = 1; i <= N - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    dfs(node_max_depth, 0, 0);
    cout << max_depth;
    return 0;
}