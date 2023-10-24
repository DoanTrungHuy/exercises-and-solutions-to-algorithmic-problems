#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MN = 2e5 + 1;
vector<ll> adj[MN];
ll N, Q;
const ll LOG = ceil(log2(MN));
ll up[MN][LOG + 1];
ll depth[MN];

void dfs(ll u, ll p) {
    for (ll v : adj[u]) {
        if (v == p) {
            continue;
        }
        up[v][0] = u;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

ll node_lca(ll u, ll v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    ll diff = depth[u] - depth[v];
    for (ll i = LOG; i >= 0; --i) {
        if (diff & (1 << i)) {
            u = up[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (ll i = LOG; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main() {
    cin >> N >> Q;
    for (ll u = 2; u <= N; ++u) {
        ll v;
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    for (ll j = 1; j <= LOG; ++j) {
        for (ll i = 1; i <= N; ++i) {
            if (up[i][j - 1] != -1) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }
    while (Q--) {
        ll a, b;
        cin >> a >> b;
        cout << node_lca(a, b) << '\n';
    }
    return 0;
}