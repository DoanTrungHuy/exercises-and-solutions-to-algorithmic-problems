#include <bits/stdc++.h>

using namespace std;

int n, m, k;
const int MAXN = 1e5 + 1;
using ll = long long;
using pr = pair<ll, int>;
vector<pr> adj[MAXN];

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w*1LL, b});
    }

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    vector<vector<ll>> top_vals(n + 1);
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();

        if ((int)top_vals[u].size() >= k) {
            continue;
        }

        top_vals[u].push_back(du);

        for (auto [w, v] : adj[u]) {
            ll dist_v = du + w;
            pq.push({dist_v, v});
        }
    }

    for (ll x : top_vals[n]) {
        cout << x << ' ';
    }

    return 0;
}