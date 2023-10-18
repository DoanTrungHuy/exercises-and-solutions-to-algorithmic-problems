#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MN = 1e5 + 10;
ll N, K;
using pr = pair<ll, ll>;
vector<pr> adj[MN];

struct Data {
    ll node, maxp, minp;

    Data() {

    }

    Data(ll node, ll maxp, ll minp) {
        this->node = node;
        this->maxp = maxp;
        this->minp = minp;
    }
};

vector<vector<Data>> par;
ll LOG;
ll depth[MN];

void dfs(ll u, ll p) {
    for (auto [v, w] : adj[u]) {
        if (v == p) {
            continue;
        }
        depth[v] = depth[u] + 1;
        par[v][0].node = u;
        par[v][0].maxp = par[v][0].minp = w;
        dfs(v, u);
    }
}

pr get(ll u, ll v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    ll mx = INT_MIN, mn = INT_MAX;
    ll diff = depth[u] - depth[v];
    for (ll i = LOG; i >= 0; --i) {
        if (diff & (1 << i)) {
            mx = max(mx, par[u][i].maxp);
            mn = min(mn, par[u][i].minp);
            u = par[u][i].node;
        }
    }
    if (u == v) {
        return {mx, mn};
    }
    for (ll i = LOG; i >= 0; --i) {
        if (par[u][i].node != par[v][i].node) {
            mx = max({mx, par[u][i].maxp, par[v][i].maxp});
            mn = min({mn, par[u][i].minp, par[v][i].minp});
            u = par[u][i].node;
            v = par[v][i].node;
        }
    }
    return {
        max({mx, par[u][0].maxp, par[v][0].maxp}),
        min({mn, par[u][0].minp, par[v][0].minp})
    };
}

int main() {
    cin >> N;
    for (ll i = 1; i <= N - 1; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    LOG = ceil(log2(N));
    par.resize(N + 1, vector<Data>(LOG + 1, {-1, INT_MIN, INT_MAX}));
    dfs(1, -1);
    for (ll j = 1; j <= LOG; ++j) {
        for (ll i = 1; i <= N; ++i) {
            if (par[i][j - 1].node != -1) {
                par[i][j].node = par[par[i][j - 1].node][j - 1].node;
                par[i][j].maxp = max(par[i][j - 1].maxp, par[par[i][j - 1].node][j - 1].maxp);
                par[i][j].minp = min(par[i][j - 1].minp, par[par[i][j - 1].node][j - 1].minp);
            }
        }
    }
    cin >> K;
    for (ll i = 1; i <= K; ++i) {
        ll D, E;
        cin >> D >> E;
        pr res = get(D, E);
        cout << res.second << ' ' << res.first << '\n';
    }
    return 0;
}