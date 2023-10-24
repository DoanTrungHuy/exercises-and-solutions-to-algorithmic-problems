#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N;
const ll MN = 2e5 + 1;
vector<ll> adj[MN];
set<ll> s[MN];
ll color[MN], ans[MN];

void dfs(ll u, ll p) {
    s[u].insert(color[u]);
    for (ll v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
        if (s[u].size() < s[v].size()) {
            swap(s[u], s[v]);
        }
        for (ll cv : s[v]) {
            s[u].insert(cv);
        }
    }
    ans[u] = s[u].size();
}

int main() {
    cin >> N;
    for (ll i = 1; i <= N; ++i) {
        ll c;
        cin >> c;
        color[i] = c;
    }
    for (ll i = 1; i <= N - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    for (ll i = 1; i <= N; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}