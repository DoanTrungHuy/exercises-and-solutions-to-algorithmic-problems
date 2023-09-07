#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MAXN = 1e5 + 1;
set<int> adj[MAXN];
int in[MAXN];
int ou[MAXN];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        in[b]++;
        ou[a]++;
    }

    int c[3] = {}, index[2] = {};

    for (int u = 1; u <= n; ++u) {
        if (in[u] == ou[u]) {
            c[0]++;
        }
        if (ou[u] - in[u] == 1) {
            index[0] = u;
            c[1]++;
        }
        if (in[u] - ou[u] == 1) {
            index[1] = u;
            c[2]++;
        }
    }

    if (index[0] != 1 or index[1] != n) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    if (!(c[0] == n - 2 and c[1] == 1 and c[2] == 1)) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    stack<int> st;
    st.push(1);
    vector<int> EC;

    while (!st.empty()) {
        int u = st.top();

        if (adj[u].empty()) {
            EC.push_back(u);
            st.pop();
        }
        else {
            int v = *adj[u].begin();
            st.push(v);
            adj[u].erase(v);
        }
    }

    if ((int)EC.size() != m + 1) {
        cout << "IMPOSSIBLE";
    }
    else {
        reverse(EC.begin(), EC.end());
        for (int u : EC) {
            cout << u << ' ';
        }
    }

    return 0;
}