#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MAXN = 1e5 + 1;
vector<int> adj[MAXN];
int indegree[MAXN] = {};

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<int> mq;
    vector<int> ans;

    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            mq.push(i);
            ans.push_back(i);
        }
    }

    while (!mq.empty()) {
        int u = mq.front();
        mq.pop();

        for (int v : adj[u]) {
            if (--indegree[v] == 0) {
                mq.push(v);
                ans.push_back(v);
            }
        }
    }

    if ((int)ans.size() != n) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (int x : ans) {
        cout << x << ' ';
    }

    return 0;
}