#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n;
const ll MN = 1e5 + 1;
vector<ll> adj[MN];

void dfs(ll u, ll p, double probability, ll depth, double &ans) {
    double n_child = 0;
    for (ll v : adj[u]) {
        if (v != p) {
            n_child++;
        }
    }
    for (ll v : adj[u]) {
        if (v != p) {
            dfs(v, u, probability / n_child, depth + 1, ans);
        }
    }
    if (n_child == 0) {
        ans += probability*depth;
    }
}

int main()
{
    cin >> n;
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    double ans = 0;
    dfs(1, 0, 1, 0, ans);
    cout << fixed << setprecision(6) << ans;
    return 0;
}