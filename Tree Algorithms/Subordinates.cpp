#include <bits/stdc++.h>

using namespace std;

int n;
const int MAXN = 2e5 + 1;
vector<int> adj[MAXN];
int dp[MAXN];

int dfs(int u) {
    for (int v : adj[u]) {
        dp[u] += 1 + dfs(v);
    }
    return dp[u];
}

int main() {
    cin >> n;

    for (int a = 2; a <= n; ++a) {
        int b;
        cin >> b;
        adj[b].push_back(a);
    }

    dfs(1);

    for (int i = 1; i <= n; ++i) {
        cout << dp[i] << ' ';
    }

    return 0;
}