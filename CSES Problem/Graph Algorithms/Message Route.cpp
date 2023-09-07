#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;
int n, m;
vector<int> adj[MAXN];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> mq;
    mq.push(1);
    int trace[n + 1];
    memset(trace, -1, sizeof(trace));
    bool visited[n + 1] = {};
    visited[1] = true;
    bool flag = false;

    while (!mq.empty()) {
        int sz = mq.size();

        for (int i = 0; i < sz; ++i) {
            int u = mq.front();
            mq.pop();

            if (u == n) {
                flag = true;
                break;
            }

            for (int v : adj[u]) {
                if (!visited[v]) {
                    mq.push(v);
                    visited[v] = true;
                    trace[v] = u;
                }
            }
        }
    }

    if (!flag) {
        cout << "IMPOSSIBLE";
    }
    else {
        vector<int> ans;
        int u = n;
        while (u != -1) {
            ans.push_back(u);
            u = trace[u];
        }
        cout << ans.size() << '\n';
        reverse(ans.begin(), ans.end());
        for (int x : ans) {
            cout << x << ' ';
        }
    }

    return 0;
}