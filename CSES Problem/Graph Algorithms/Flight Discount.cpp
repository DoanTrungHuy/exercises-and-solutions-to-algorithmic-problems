#include <bits/stdc++.h>

using namespace std;

int n, m;
using ll = long long;
using pr = pair<ll, int>;
using tp = tuple<ll, int, int>;

vector<tp> edges;
vector<vector<pr>> adj[2];
vector<ll> dist[2];

#define N_CASE 2

void dijkstra(vector<vector<pr>> _adj, int start, int t) {
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pq.push({dist[t][start] = 0LL, start});

    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();

        if (dist[t][u] != du) {
            continue;
        }

        for (auto [w, v] : _adj[u]) {
            if (du + w < dist[t][v]) {
                dist[t][v] = du + w;
                pq.push({dist[t][v], v});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < N_CASE; ++i) {
        adj[i].resize(n + 1), dist[i].resize(n + 1, LLONG_MAX);
    }

    for (int i = 1; i <= m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({1LL*w, a, b});
        adj[0][a].push_back({1LL*w, b});
        adj[1][b].push_back({1LL*w, a});
    }

    for (int i = 0; i < N_CASE; ++i) {
        dijkstra(adj[i], (i == 0 ? 1 : n), i);
    }

    ll ans = LLONG_MAX;

    for (auto [w, a, b] : edges) {
        if (dist[0][a] == LLONG_MAX or dist[1][b] == LLONG_MAX) {
            continue; 
        }
        ans = min(ans, dist[0][a] + w/2 + dist[1][b]);
    }

    cout << ans;
    
    return 0;
}