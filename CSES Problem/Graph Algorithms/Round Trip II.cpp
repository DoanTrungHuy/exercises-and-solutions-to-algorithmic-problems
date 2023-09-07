#include <bits/stdc++.h>
 
using namespace std;

int n, m;
const int MAXN = 1e5 + 1;
vector<int> adj[MAXN];
int color[MAXN] = {}, trace[MAXN] = {};

void dfs(int u) {
    color[u] = 1;
    
    for (int v : adj[u]) {
        if (color[v] == 0) {
            trace[v] = u;
            dfs(v);
        }
        else if (color[v] == 1) {
            vector<int> ans;
            ans.push_back(u);
            while (ans.back() != v) {
                ans.push_back(trace[ans.back()]);
            }
            ans.push_back(u);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << '\n';
            for (int x : ans) {
                cout << x << ' ';
            }
            exit(0);
        }
    }

    color[u] = 2;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            trace[i] = i;
            dfs(i);
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}