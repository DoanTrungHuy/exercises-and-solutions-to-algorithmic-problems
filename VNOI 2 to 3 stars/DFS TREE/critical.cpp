#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll N, M;
const ll MN = 2e4 + 1;
vector<ll> adj[MN];
ll num[MN], low[MN];
ll id_node = 0;
bool joint[MN];
ll sum[MN];
ll parent[MN];
ll id_connect = 0;
ll mapping_connect[MN], size_in_connected[MN];

void dfs(ll u, ll p) {
    mapping_connect[u] = id_connect;
    size_in_connected[id_connect]++;
    num[u] = low[u] = ++id_node;
    sum[u] = 1;
    ll child = 0;
    for (ll v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        }
        else {
            parent[v] = u;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            sum[u] += sum[v];
            child++;
            if (u == p and child > 1) {
                joint[u] = true;
            }
            else if (u != p and low[v] >= num[u]) {
                joint[u] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (ll i = 0; i < M; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (ll i = 1; i <= N; ++i) {
        if (mapping_connect[i] == 0) {
            ++id_connect;
            dfs(i, i);
        }
    }
    double s = 0;
    for (ll u = 1; u <= N; ++u) {
        if (joint[u]) {
            ll t = 0, sum_u = 0;
            for (ll v : adj[u]) {
                if (parent[v] == u and low[v] >= num[u]) {
                    t += sum[v] * (size_in_connected[mapping_connect[u]] - 1 - sum[v]);
                    sum_u += sum[v];
                }
            }
            t += (size_in_connected[mapping_connect[u]] - sum_u - 1) * sum_u;
            s += t / 2;
        }
    }
    cout << fixed << setprecision(2) << (s/N);
    return 0;
}