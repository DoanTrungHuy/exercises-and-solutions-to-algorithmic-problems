#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;
using ll = long long;
using pr = pair<ll, int>;
vector<pr> adj[MAXN];
int n, m;

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w*1LL, b});
    }

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    vector<ll> dist(n + 1, LLONG_MAX);
    pq.push({dist[1] = 0, 1});

    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();

        if (dist[u] != du) {
            continue;
        }

        for (auto [dv, v] : adj[u]) {
            if (du + dv < dist[v]) {
                dist[v] = du + dv;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << ' ';
    }
    return 0;
}