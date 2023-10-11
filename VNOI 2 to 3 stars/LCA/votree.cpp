#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n, m;
const ll MN = 7e4 + 10;
vector<vector<ll>> adj;
vector<vector<ll>> par;
ll depth[MN];

void dfs(ll u, ll p) {
    for (ll v : adj[u]) {
        if (v == p) {
            continue;
        }
        depth[v] = depth[u] + 1;
        par[v][0] = u;
        dfs(v, u);
    }
}

ll node_lca(ll u, ll v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    ll diff = depth[u] - depth[v];
    const ll LOG = ceil(log2(n));
    for (ll i = LOG; i >= 0; --i) {
        if (diff & (1 << i)) {
            u = par[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (ll i = LOG; i >= 0; --i) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

ll tree[MN*4];

void update(ll node, ll left, ll right, ll index, ll value) {
    if (index < left or index > right) {
        return;
    }
    if (left == right) {
        tree[node] = value;
        return;
    }
    ll mid = (left + right) / 2;
    update(node*2, left, mid, index, value);
    update(node*2 + 1, mid + 1, right, index, value);
    if (tree[node*2] == -1 or tree[node*2 + 1] == -1) {
        tree[node] = (tree[node*2] == -1 ? tree[node*2 + 1] : tree[node*2]);
    }
    else {
        tree[node] = node_lca(tree[node*2], tree[node*2 + 1]);
    }
}

ll get_lca(ll node, ll left, ll right, ll q_left, ll q_right) {
    if (q_left > right or left > q_right) {
        return -1;
    }
    if (q_left <= left and right <= q_right) {
        return tree[node];
    }
    ll mid = (left + right) / 2;
    ll left_node = get_lca(node*2, left, mid, q_left, q_right);
    ll right_node = get_lca(node*2 + 1, mid + 1, right, q_left, q_right);
    if (left_node == -1 or right_node == -1) {
        return left_node == -1 ? right_node : left_node;
    }
    return node_lca(left_node, right_node);
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    for (ll i = 1; i <= n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    const ll LOG = ceil(log2(n));
    par.resize(n + 1, vector<ll>(LOG + 1, -1));
    dfs(1, -1);
    for (ll j = 1; j <= LOG; ++j) {
        for (ll i = 1; i <= n; ++i) {
            if (par[i][j - 1] != -1) {
                par[i][j] = par[par[i][j - 1]][j - 1];
            }
        }
    }
    memset(tree, -1, sizeof(tree));
    for (ll i = 1; i <= n; ++i) {
        update(1, 1, n, i, i);
    }
    for (ll i = 1; i <= m; ++i) {
        ll u, v;
        cin >> u >> v;
        cout << get_lca(1, 1, n, u, v) << '\n';
    }
    return 0;
}