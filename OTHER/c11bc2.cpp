#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N, M;
const ll MN = 1e4 + 100;
ll a[MN];
using pr = pair<ll, ll>;
vector<pr> adj[MN];
const ll LOG = ceil(log2(MN));
ll up[MN][LOG + 1];
ll dp[MN][LOG + 1];
ll depth[MN];

void dfs(ll u, ll p) {
    for (const auto &[v, w] : adj[u]) {
        if (v == p) {
            continue;
        }
        up[v][0] = u;
        depth[v] = depth[u] + 1;
        dp[v][0] = (w == 2);
        dfs(v, u);
    }
}

bool check_(ll u, ll v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    ll diff = depth[u] - depth[v];
    for (ll i = LOG; i >= 0; --i) {
        if (diff & (1 << i)) {
            if (dp[u][i]) {
                return true;
            }
            u = up[u][i]; 
        }
    }
    if (u == v) {
        return false;
    }
    for (ll i = LOG; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            if (dp[u][i] or dp[v][i]) {
                return true;
            }
            u = up[u][i];
            v = up[v][i];
        }
    }
    return dp[u][0] or dp[v][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (ll i = 2; i <= N; ++i) {
        ll x, k;
        cin >> x >> k;
        adj[i].push_back({x, k});
        adj[x].push_back({i, k});
    }
    memset(up, -1, sizeof(up));
    memset(dp, 0, sizeof(dp));
    dfs(1, 1);
    for (ll j = 1; j <= LOG; ++j) {
        for (ll i = 1; i <= N; ++i) {
            if (up[i][j - 1] != -1) {
                up[i][j] = up[up[i][j - 1]][j - 1];
                dp[i][j] = dp[i][j - 1] or dp[up[i][j - 1]][j - 1];
            }
        }
    }
    for (ll i = 0; i < M; ++i) {
        ll u, v;
        cin >> u >> v;
        cout << (check_(u, v) ? "YES" : "NO") << '\n';
    }
    return 0;
}