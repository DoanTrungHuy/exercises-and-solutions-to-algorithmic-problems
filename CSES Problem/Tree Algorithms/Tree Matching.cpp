#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N;
const ll MN = 2e5 + 2;
bool visited[MN];
ll ans = 0;
vector<ll> adj[MN];

void dfs(ll u, ll p) {
    for (ll v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            if (!visited[u] and !visited[v]) {
                ans++;
                visited[u] = visited[v] = true;
            }
        }
    }
}

int main() {
    cin >> N;
    for (ll i = 1; i <= N - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}