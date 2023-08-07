#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2501;
int n, m;
using ll = long long;
using tp = tuple<ll, int, int>;
vector<tp> edges;
const ll inf = 1e15;

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({1LL*w, a, b});
    }

    vector<ll> dist(n + 1, -inf);
    dist[1] = 0;

    for (int i = 0; i < n; ++i) {
        for (auto [w, u, v] : edges) {
            if (dist[u] != -inf and dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (auto [w, u, v] : edges) {
            if (dist[u] != -inf and dist[v] < dist[u] + w) {
                dist[v] = inf;
            }
        }
    }

    cout << (dist[n] == inf ? -1 : dist[n]) << '\n';

    return 0;
}