#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll T;
ll N, M;
using tp = tuple<ll, ll, ll>;
vector<tp> edges;

class DSU {
private:
    vector<ll> parent;
    vector<ll> sz;

public:
    DSU(ll n = 0) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for (ll i = 0; i <= n; ++i) {
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

        if (sz[u] < sz[v]) {
            swap(u, v);
        }

        parent[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (ll i = 0; i < M; ++i) {
            ll u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }
        sort(edges.begin(), edges.end(), [&](const tp a, const tp b) {
            return get<2>(a) > get<2>(b);
        });
        DSU dsu(N);
        ll res = LLONG_MAX;
        for (ll i = 0; i < M; ++i) {
            const auto [u, v, w] = edges[i];
            if (!dsu._union(u, v)) {
                continue;
            }
            if (dsu.find(1) == dsu.find(N)) {
                res = w;
                break;
            }
        }
        if (res == LLONG_MAX) {
            cout << -1 << '\n';
        }
        else {
            cout << res << '\n';
        }
        edges.clear();
    }
    return 0;
}