#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MN = 101;
ll n, m;
vector<ll> adj[MN];
ll num[MN], low[MN];
ll sum[MN];
ll id_node = 0;

void dfs(ll u, ll p) {
    num[u] = low[u] = ++id_node;
    sum[u] = 1;
    for (ll v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        }
        else {
            dfs(v, u);
            sum[u] = sum[u] + sum[v];
            low[u] = min(low[u], low[v]);
        }
    }
}

int main() {
    cin >> n >> m;
    for (ll i = 1; i <= m; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    ll res = 0;
    for (ll i = 1; i <= n; ++i) {
        if (num[i] == low[i]) {
            res += (n - sum[i])*sum[i];
        }
    }
    cout << res;
    return 0;
}