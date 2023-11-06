#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, M;
const ll MN = 1e5 + 10;
vector<ll> adj[MN];
ll indegree[MN];

int main() {
    cin >> N >> M;
    memset(indegree, 0, sizeof(indegree));
    for (ll i = 1; i <= M; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<ll> mq;
    for (ll i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            mq.push(i);
        }
    }
    ll dp[N + 1];
    memset(dp, 0, sizeof(dp));
    while (!mq.empty()) {
        const ll u = mq.front();
        mq.pop();

        for (ll v : adj[u]) {
            dp[v] = max(dp[v], 1 + dp[u]);
            if (--indegree[v] == 0) {
                mq.push(v);
            }
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= N; ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}