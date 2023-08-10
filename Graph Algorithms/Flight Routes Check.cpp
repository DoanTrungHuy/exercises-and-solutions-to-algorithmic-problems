#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;
int n, m;
vector<int> adj[2][MAXN];
bool visited[MAXN];

void dfs(int u, int t) {
    visited[u] = true;

    for (int v : adj[t][u]) {
        if (!visited[v]) {
            dfs(v, t);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[0][a].push_back(b);
        adj[1][b].push_back(a);
    }

    memset(visited, false, sizeof(visited));

    dfs(1, 0);

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cout << "NO" << '\n';
            cout << 1 << ' ' << i;
            return 0;
        }
    }

    memset(visited, false, sizeof(visited));

    dfs(1, 1);

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cout << "NO" << '\n';
            cout << i << ' ' << 1;
            return 0;
        }
    }

    cout << "YES";

    return 0;
}