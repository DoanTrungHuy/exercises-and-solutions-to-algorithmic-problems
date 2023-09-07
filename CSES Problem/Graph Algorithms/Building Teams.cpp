#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MAXN = 1e5 + 1;
vector<int> adj[MAXN];
int color[MAXN] = {};

bool dfs(int u, int c) {
    color[u] = c;
    for (int v : adj[u]) {
        if (!color[v]) {
            if (!dfs(v, c == 1 ? 2 : 1)) {
                return false;
            }
        }
        else if (color[v] == c) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (!color[i]) {
            if (!dfs(i, 1)) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << color[i] << ' ';
    }

    return 0;
}