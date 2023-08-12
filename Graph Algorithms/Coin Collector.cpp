#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;
int k[MAXN];
vector<int> adj[MAXN];
int n, m;
int num[MAXN], low[MAXN];
int step = 0;
int del[MAXN], par[MAXN];
int idSCC = 0;
stack<int> st;
using ll = long long;
ll sum[MAXN];

void tarjan(int u) {
    num[u] = low[u] = ++step;
    st.push(u);

    for (int v : adj[u]) {
        if (del[v]) {
            continue;
        }
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        }
        else {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if (num[u] == low[u]) {
        idSCC++;
        int t;
        do {
            t = st.top();
            st.pop();
            del[t] = 1;
            par[t] = idSCC;
            sum[idSCC] += k[t];
        } while (t != u);
    }
}

vector<int> cd_adj[MAXN];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
    }

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int u = 1; u <= n; ++u) {
        if (num[u] == 0) {
            tarjan(u);
        }
    }

    int indegree[MAXN];

    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            if (par[v] != par[u]) {
                cd_adj[par[v]].push_back(par[u]);
                indegree[par[u]]++;
            }
        }
    }

    queue<int> mq;

    ll dp[MAXN] = {};

    for (int u = 1; u <= idSCC; ++u) {
        if (indegree[u] == 0) {
            mq.push(u);
            dp[u] = sum[u];
        }
    }

    while (!mq.empty()) {
        int u = mq.front();
        mq.pop();

        for (int v : cd_adj[u]) {
            dp[v] = max(dp[v], dp[u] + sum[v]);
            if (--indegree[v] == 0) {
                mq.push(v);
            }
        }
    }

    ll max_path_sum = 0LL;

    for (int u = 1; u <= n; ++u) {
        max_path_sum = max(max_path_sum, dp[u]);
    }

    cout << max_path_sum;

    return 0;
}