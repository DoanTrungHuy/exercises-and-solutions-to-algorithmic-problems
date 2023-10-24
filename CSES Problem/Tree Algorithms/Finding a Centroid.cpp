#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N;
const ll MN = 2e5 + 1;
vector<ll> adj[MN];
ll child[MN];

void dfs(ll u, ll p) {
    child[u] = 1;
    for (ll v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
        child[u] += child[v];
    }
}

ll find_centroid(ll u, ll p) {
    for (ll v : adj[u]) {
        if (v != p and child[v] > N / 2) {
            return find_centroid(v, u);
        }
    }
    return u;
}

int main() {
    cin >> N;
    for (ll i = 1; i <= N - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    cout << find_centroid(1, 0);
    return 0;
}