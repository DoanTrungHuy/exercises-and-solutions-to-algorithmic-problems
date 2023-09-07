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
    vector<int> dp(n + 1, INT_MIN);
    dp[1] = 0;

    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            mq.push(i);
        }
    }

    vector<int> trace(n + 1, -1);

    while (!mq.empty()) {
        int u = mq.front();
        mq.pop();

        for (int v : adj[u]) {
            if (dp[u] + 1 > dp[v]) {
                dp[v] = dp[u] + 1;
                trace[v] = u;
            }
            if (--indegree[v] == 0) {
                mq.push(v);
            }
        }
    }

    if (dp[n] < 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> ans;

    ans.push_back(n);

    while (ans.back() != 1) {
        ans.push_back(trace[ans.back()]);
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';

    for (int x : ans) {
        cout << x << ' ';
    }

    return 0;
}