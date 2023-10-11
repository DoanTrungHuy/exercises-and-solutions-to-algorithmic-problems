#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll t, n;
const ll MN = 10005;
using pr = pair<ll, ll>;
vector<vector<pr>> adj;
vector<vector<ll>> par;
ll depth[MN], sum[MN];

void dfs(ll u, ll p) {
    par[u][0] = p;
    for (const auto &[v, w] : adj[u]) {
        if (v == p) {
            continue;
        }
        depth[v] = depth[u] + 1;
        sum[v] = sum[u] + w;
        dfs(v, u);
    }
}

ll node_lca(ll u, ll v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    ll diff = depth[u] - depth[v];
    const ll LOG = ceil(log2(n));
    for (ll i = LOG; i >= 0; --i) {
        if (diff & (1 << i)) {
            u = par[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (ll i = LOG; i >= 0; --i) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

ll calc_dist(ll u, ll v) {
    return depth[u] + depth[v] - 2*depth[node_lca(u, v)];
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        adj.resize(n + 1);
        for (ll i = 1; i <= n - 1; ++i) {
            ll u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        memset(depth, 0, sizeof(depth));
        memset(sum, 0, sizeof(sum));
        const ll LOG = ceil(log2(n));
        par.resize(n + 1, vector<ll>(LOG + 1, -1));
        dfs(1, -1);
        for (ll j = 1; j <= LOG; ++j) {
            for (ll i = 1; i <= n; ++i) {
                if (par[i][j - 1] != -1) {
                    par[i][j] = par[par[i][j - 1]][j - 1];
                }
            }
        }
        string word;
        do {
            cin >> word;
            if (word == "DIST") {
                ll u, v;
                cin >> u >> v;
                cout << sum[u] + sum[v] - 2*sum[node_lca(u, v)] << '\n';
            }
            else if (word == "KTH") {
                ll u, v, k;
                cin >> u >> v >> k;
                ll lca = node_lca(u, v);
                ll dist_of_u_to_root = calc_dist(u, lca);
                ll dist_of_v_to_root = calc_dist(v, lca);

                auto jump = [&](ll node, ll lift) -> ll {
                    for (ll i = LOG; i >= 0; --i) {
                        if ((lift & (1 << i)) and par[node][i] != -1) {
                            node = par[node][i];
                        }
                    }
                    return node;
                };

                k -= 1;
                
                if (dist_of_u_to_root >= k) {
                    cout << jump(u, k) << '\n';
                }
                else {
                    cout << jump(v, dist_of_v_to_root - (k - dist_of_u_to_root)) << '\n';
                }
            }
        } while (word != "DONE");
        for (ll i = 1; i <= n; ++i) {
            adj[i].clear();
        }
        par.clear();
    }
    return 0;
}