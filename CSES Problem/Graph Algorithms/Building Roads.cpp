#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;
int n, m;

class DSU {
public:
    vector<int> parent;
    int n;
    int group;

    DSU(int n = 0) {
        this->n = n;
        this->group = n;
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void _union(int u, int v) {
        u = find(u);
        v = find(v);

        if (u != v) {
            parent[u] = v;
            group--;
        }
    }
};

int main() {
    cin >> n >> m;

    DSU dsu(n);

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        dsu._union(a, b);
    }

    cout << dsu.group - 1 << '\n';

    unordered_set<int> us;

    for (int i = 1; i <= n; ++i) {
        us.insert(dsu.find(i));
    }

    vector<int> v(us.begin(), us.end());

    for (int i = 0; i < (int)v.size() - 1; ++i) {
        cout << v[i] << ' ' << v[i + 1] << '\n';
    }

    return 0;
}