#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, M;
const ll MN = 1e3 + 10; 

struct DSU {
    vector<ll> parent;

    DSU(ll n = 0) {
        parent.resize(n + 1);
        for (ll i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    ll find(ll u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool _union(ll u, ll v) {
        u = find(u);
        v = find(v);
        if (u == v) {
            return false;
        }
        parent[u] = v;
        return true;
    }
};

using tp = tuple<ll, ll, ll>;

int main() {
    cin >> N >> M;
    vector<tp> edges;
    for (ll i = 0; i < M; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end(), [&](tp &a, tp &b) {
        return get<2>(a) < get<2>(b);
    });
    DSU dsu(N);
    ll res = 0;
    for (ll i = 0; i < M; ++i) {
        auto [u, v, w] = edges[i];
        if (!dsu._union(u, v)) {
            continue;
        }
        res = max(res, w);
    }
    cout << res;
    return 0;
}