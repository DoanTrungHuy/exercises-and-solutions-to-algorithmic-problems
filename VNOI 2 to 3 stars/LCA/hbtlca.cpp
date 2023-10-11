#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
const int MN = 1e5 + 1;
vector<int> adj[MN];
int depth[MN];
const int LOG = 16;
int par[MN][LOG + 1];

void dfs(int u, int p) {
    par[u][0] = p;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int node_lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    int diff = depth[u] - depth[v];
    for (int i = LOG; i >= 0; --i) {
        if (diff & (1 << i)) {
            u = par[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = LOG; i >= 0; --i) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}


int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    while (cin >> n, n) {
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
        }
        for (int i = 1; i <= n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(par, -1, sizeof(par));
        memset(depth, 0, sizeof(depth));
        dfs(1, -1);
        for (int j = 1; j <= LOG; ++j) {
            for (int i = 1; i <= n; ++i) {
                if (par[i][j - 1] != -1) {
                    par[i][j] = par[par[i][j - 1]][j - 1];
                }
            }
        }
        cin >> m;
        int root = 1;
        while (m--) {
            char c;
            cin >> c;
            if (c == '!') {
                cin >> root;
            }
            else {
                int u, v;
                cin >> u >> v;
                cout << (node_lca(u, v) ^ node_lca(u, root) ^ node_lca(v, root)) << '\n';
            }
        }
    }
    return 0;
}