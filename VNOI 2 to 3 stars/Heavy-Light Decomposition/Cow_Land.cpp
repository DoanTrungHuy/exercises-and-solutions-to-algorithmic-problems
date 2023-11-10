#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MN = 1e5 + 10;
ll N, Q;
ll e[MN];
vector<ll> adj[MN];
ll depth[MN], sz[MN];
ll par[MN];

void dfs(ll u, ll p) {
    sz[u] = 1;
    for (ll v : adj[u]) {
        if (v == p) {
            continue;
        }
        par[v] = u;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

ll chain_id[MN], chain_head[MN];
ll mp_vertex[MN], pos[MN];
ll curr_chain = 1, curr_pos = 1;

void hld(ll u, ll p) {
    if (!chain_head[curr_chain]) {
        chain_head[curr_chain] = u;
    }
    chain_id[u] = curr_chain;
    pos[u] = curr_pos;
    mp_vertex[curr_pos] = u;
    curr_pos++;
    ll next_vertex = 0;
    for (ll v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (next_vertex == 0 or sz[next_vertex] < sz[v]) {
            next_vertex = v;
        }
    }
    if (next_vertex != 0) {
        hld(next_vertex, u);
    }
    for (ll v : adj[u]) {
        if (v == p or v == next_vertex) {
            continue;
        }
        curr_chain++;
        hld(v, u);
    }
}

ll tree[MN*4];

void update(ll node, ll left, ll right, ll index, ll value) {
    if (left > index or right < index) {
        return;
    }
    if (left == right) {
        tree[node] = value;
        return;
    }
    ll mid = (left + right) / 2;
    update(node*2, left, mid, index, value);
    update(node*2 + 1, mid + 1, right, index, value);
    tree[node] = tree[node*2] ^ tree[node*2 + 1];
}

ll get(ll node, ll left, ll right, ll q_left, ll q_right) {
    if (q_left > right or q_right < left) {
        return 0;
    }
    if (q_left <= left and right <= q_right) {
        return tree[node];
    }
    ll mid = (left + right) / 2;
    ll left_node = get(node*2, left, mid, q_left, q_right);
    ll right_node = get(node*2 + 1, mid + 1, right, q_left, q_right);
    return left_node ^ right_node;
}

ll node_lca(ll u, ll v) {
    while (chain_id[u] != chain_id[v]) {
        if (chain_id[u] > chain_id[v]) {
            u = par[chain_head[chain_id[u]]];
        }
        else {
            v = par[chain_head[chain_id[v]]];
        }
    }
    if (depth[u] > depth[v]) {
        return v;
    }
    return u;
}

ll query(ll u, ll v) {
    ll lca = node_lca(u, v);
    ll ans = 0;

    while (chain_id[u] != chain_id[lca]) {
        ans ^= get(1, 1, N, pos[chain_head[chain_id[u]]], pos[u]);
        u = par[chain_head[chain_id[u]]];
    }

    while (chain_id[v] != chain_id[lca]) {
        ans ^= get(1, 1, N, pos[chain_head[chain_id[v]]], pos[v]);
        v = par[chain_head[chain_id[v]]];
    }

    if (depth[u] < depth[v]) {
        ans ^= get(1, 1, N, pos[u], pos[v]);
    }
    else {
        ans ^= get(1, 1, N, pos[v], pos[u]);
    }

    return ans;
}

int main() {
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> Q;
    for (ll i = 1; i <= N; ++i) {
        cin >> e[i];
    }
    for (ll i = 1; i <= N - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 1);
    hld(1, 1);
    for (ll i = 1; i <= N; ++i) {
        update(1, 1, N, pos[i], e[i]);
    }
    while (Q--) {
        ll c;
        cin >> c;
        if (c == 1) {
            ll i, v;
            cin >> i >> v;
            update(1, 1, N, pos[i], v);
        }
        else {
            ll i, j;
            cin >> i >> j;
            cout << query(i, j) << '\n';
        }
    }
    return 0;
}