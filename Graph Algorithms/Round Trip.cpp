#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
const int MAXN = 1e5 + 1;
vector<int> adj[MAXN];
bool visited[MAXN] = {};
int parent[MAXN] = {};

vector<int> ans;
bool flag = false;
 
void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (flag) {
            continue;
        }
        if (parent[v]) {
            flag = true;
            ans.push_back(u);
            while (ans.back() != v) {
                ans.push_back(parent[ans.back()]);
            }
            ans.push_back(u);
        }
        parent[v] = u;
        dfs(v, u);
    }
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
        if (!parent[i]) {
            parent[i] = i;
            dfs(i, 0);
            if (flag) {
                break;
            }
        }
    }

    if (flag) {
        cout << ans.size() << '\n';
        for (int x : ans) {
            cout << x << ' ';
        }
    }
    else {
        cout << "IMPOSSIBLE";
    }
 
    return 0;
}