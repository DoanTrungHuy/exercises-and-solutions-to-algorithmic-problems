#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MN = 2e5 + 10;
vector<ll> adj[MN];
ll N;
ll c_node[MN];
ll ans[MN];

void dfs(ll u, ll p, ll d) {
    ans[1] += d;
    c_node[u] = 1;
    for (ll v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u, d + 1);
        c_node[u] += c_node[v];
    }
}

void dfs2(ll u, ll p) {
    for (ll v : adj[u]) {
        if (v == p) {
            continue;
        }
        ans[v] = ans[u] + (N - c_node[v]) - c_node[v];
        dfs2(v, u);
    }
}

int main() {
    cin >> N;
    for (ll i = 0; i < N - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1, 0);
    dfs2(1, -1);
    for (ll i = 1; i <= N; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}