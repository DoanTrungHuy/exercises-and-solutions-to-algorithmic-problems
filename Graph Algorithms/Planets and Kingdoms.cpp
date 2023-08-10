#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;
int n, m;
vector<int> adj[MAXN];
bool visited[MAXN];
int cur[MAXN], low[MAXN];
int step = 0;
stack<int> st;
int idSCC = 0;
bool del[MAXN];
int ans[MAXN];

void dfs(int u) {
    cur[u] = low[u] = ++step;
    st.push(u);

    for (int v : adj[u]) {
        if (del[v]) {
            continue;
        }
        if (cur[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else {
            low[u] = min(low[u], cur[v]);
        }
    }

    if (low[u] == cur[u]) {
        idSCC++;
        int t;
        do {
            t = st.top();
            st.pop();
            del[t] = true;
            ans[t] = idSCC;
        } while (u != t);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) {
        if (cur[i] == 0) {
            dfs(i);
        }
    }

    cout << idSCC << '\n';

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}