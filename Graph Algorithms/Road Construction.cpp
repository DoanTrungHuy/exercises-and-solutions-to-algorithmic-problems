#include <bits/stdc++.h>

using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    int group;
    int max_component = 1;

    DSU(int n = 0) {
        parent.resize(n);
        rank.resize(n, 1);

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
            if (rank[u] > rank[v]) {
                parent[v] = u;
                rank[u] += rank[v];
            }
            else {
                parent[u] = v;
                rank[v] += rank[u];
            }
            max_component = max({max_component, rank[v], rank[u]});
            group--;
            return true;
        }

        return false;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        dsu._union(a, b);
        cout << dsu.group << ' ' << dsu.max_component << '\n';
    }

    return 0;
}