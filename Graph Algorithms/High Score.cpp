#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2501;
int n, m;
using ll = long long;
using tp = tuple<ll, int, int>;
vector<tp> edges;
vector<vector<int>> visited;

void dfs(vector<vector<int>> &adj, int t, int u) {
    visited[t][u] = true;

    for (int v : adj[u]) {
        if (!visited[t][v]) {
            dfs(adj, t, v);
        }
    }
}

int main() {
    cin >> n >> m;

    vector<vector<int>> adj[2];
    visited.resize(2, vector<int>(n + 1, false));

    adj[0].resize(n + 1);
    adj[1].resize(n + 1);

    for (int i = 1; i <= m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({-1LL*w, a, b});
        adj[0][a].push_back(b);
        adj[1][b].push_back(a);
    }

    dfs(adj[0], 0, 1);
    dfs(adj[1], 1, n);

    vector<ll> dist(n + 1, LLONG_MAX);
    dist[1] = 0;

    for (int i = 0; i < n; ++i) {
        for (auto [w, u, v] : edges) {
            if (dist[u] != LLONG_MAX and dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;

                if (i == n - 1 and visited[0][v] and visited[1][v]) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << -1LL*dist[n] << '\n';
    return 0;
}