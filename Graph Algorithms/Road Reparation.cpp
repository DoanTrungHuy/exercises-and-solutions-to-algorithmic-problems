#include <bits/stdc++.h>

using namespace std;

class DSU {
public:
    vector<int> parent;
    int group;

    DSU(int n = 0) {
        parent.resize(n);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        this->group = n;
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool _union(int u, int v) {
        u = find(u);
        v = find(v);

        if (u != v) {
            parent[u] = v;
            group--;
            return true;
        }

        return false;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges;

    for (int i = 1; i <= m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        edges.push_back({a, b, w});
    }

    sort(edges.begin(), edges.end(), [&](array<int, 3> a, array<int, 3> b) {
        return a[2] < b[2];
    });

    long long res = 0;

    DSU dsu(n);

    for (array<int, 3> edge : edges) {
        int a = edge[0];
        int b = edge[1];
        int w = edge[2];

        if (dsu._union(a, b)) {
            res += 1LL*w;
        }
    }

    if (dsu.group == 1) {
        cout << res;
    }
    else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}