#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MAXN = 1e5 + 1;
using ll = long long;
using pr = pair<ll, int>;
vector<pr> adj[MAXN];
const int MOD = 1e9 + 7;

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
    
    int flights[3][n + 1] = {};

    for (int i = 2; i <= n; ++i) {
        flights[0][i] = INT_MIN;
        flights[1][i] = INT_MAX;
        flights[2][i] = 0;
    }

    flights[0][1] = 0;
    flights[1][1] = 0;
    flights[2][1] = 1;

    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();

        for (auto [w, v] : adj[u]) {
            ll new_dist_v = w + du;
            if (new_dist_v < dist[v]) {
                flights[0][v] = flights[0][u] + 1;
                flights[1][v] = flights[1][u] + 1;
                flights[2][v] = flights[2][u];
                pq.push({dist[v] = new_dist_v, v});
            }
            else if (new_dist_v == dist[v]) {
                flights[0][v] = max(flights[0][v], flights[0][u] + 1);
                flights[1][v] = min(flights[1][v], flights[1][u] + 1);
                flights[2][v] = (flights[2][v] + flights[2][u]) % MOD;
            }
        }
    }

    cout << dist[n] << ' ' << flights[2][n] << ' ' << flights[1][n] << ' ' << flights[0][n];

    return 0;
}