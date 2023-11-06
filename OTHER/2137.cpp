#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MN = 5e4 + 10;
ll N, M;
vector<ll> adj[MN];
ll indegree[MN];
bitset<MN> dp[MN];

int main() {
    cin >> N >> M;
    memset(indegree, 0, sizeof(indegree));
    for (ll i = 1; i <= M; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        indegree[u]++;
    }
    
    queue<ll> mq;
    for (ll i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            mq.push(i);
        }
        dp[i].set(i);
    }

    while (!mq.empty()) {
        ll u = mq.front();
        mq.pop();

        for (ll v : adj[u]) {
            dp[v] |= dp[u];
            --indegree[v];
            if (indegree[v] == 0) {
                mq.push(v);
            }
        }
    }

    for (ll i = 1; i <= N; ++i) {
        cout << dp[i].count() << ' ';
    }
    return 0;
}