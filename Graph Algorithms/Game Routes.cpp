#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MAXN = 1e5 + 1;
vector<int> adj[MAXN];
using ll = long long;
const int MOD = 1e9 + 7;
int indegree[MAXN] = {};

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    vector<ll> dp(n + 1, 0);
    dp[1] = 1;
    queue<int> mq;
    
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            mq.push(i);
        }
    }

    while (!mq.empty()) {
        int u = mq.front();
        mq.pop();

        for (int v : adj[u]) {
            dp[v] = (dp[u] + dp[v]) % MOD;
            if (--indegree[v] == 0) {
                mq.push(v);
            }
        }
    }

    cout << dp[n];
    return 0;
}