#include <bits/stdc++.h>

using namespace std;

const int MN = 255;
vector<vector<int>> par;
vector<int> adj[MN];
int A[MN], H[MN];
int LOG;

void dfs(int u, int p, int c) {
    par[u][0] = p;
    H[u] = c;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, c + 1);
        }
    }
}

int lca(int u, int v) {
    if (H[u] < H[v]) {
        swap(u, v);
    }

    int diff = H[u] - H[v];

    for (int i = LOG; i >= 0; --i) {
        if ((diff >> i) & 1) {
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
    int n, m;
    cin >> n >> m;
    LOG = ceil(log2(n));
    par.resize(n + 1, vector<int>(LOG + 1, -1));
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < m; ++i) {
        cin >> A[i];
    }
    dfs(1, -1, 1);
    for (int j = 1; j <= LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (par[i][j - 1] != -1) {
                par[i][j] = par[par[i][j - 1]][j - 1];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m - 1; ++i) {
        ans += H[A[i]] + H[A[i + 1]] - 2 * H[lca(A[i], A[i + 1])];
    }
    cout << ans << endl;
    return 0;
}