#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MAXN = 20;
vector<int> adj[MAXN];
int memo[MAXN][1 << MAXN];
const int MOD = 1e9 + 7;
using ll = long long;

ll dp(int u, int mask) {
    if (__builtin_popcount(mask) == n) {
        return 1;
    }
    else if (u == n - 1) {
        return 0;
    }
    if (memo[u][mask] != -1) {
        return memo[u][mask];
    }
    ll ans = 0;
    for (int v : adj[u]) {
        if (mask & (1 << v)) {
            continue;
        }
        ans = (ans + dp(v, mask ^ (1 << v))) % MOD;
    }
    return memo[u][mask] = ans;
}

int main() {
    memset(memo, -1, sizeof(memo));

    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }

    cout << dp(0, 1 << 0);
    return 0;
}