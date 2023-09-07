#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MAXN = 1e5 + 1;
set<int> adj[MAXN];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;

        adj[a].insert(b);
        adj[b].insert(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() & 1) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    stack<int> st;
    vector<int> EC;

    st.push(1);

    while (!st.empty()) {
        int u = st.top();

        if (!adj[u].empty()) {
            int v = *adj[u].begin();
            st.push(v);
            adj[u].erase(v);
            adj[v].erase(u);
        }
        else {
            EC.push_back(u);
            st.pop();
        }
    }

    if ((int)EC.size() != m + 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (int u : EC) {
        cout << u << ' ';
    }

    return 0;
}