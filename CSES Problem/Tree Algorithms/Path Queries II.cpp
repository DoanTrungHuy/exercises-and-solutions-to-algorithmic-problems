#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
using namespace std;
 
const int MN = 2e5 + 1;
int N, Q;
int val[MN];
vector<int> adj[MN];
const int LOG = ceil(log2(MN));
int depth[MN], sz[MN], par[MN], up[MN][LOG + 1];
 
void dfs(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        up[v][0] = u;
        par[v] = u;
        depth[v] = depth[u] + 1; 
        dfs(v, u);
        sz[u] += sz[v];
    }
}
 
int chain_id[MN], chain_head[MN];
int pos[MN];
int curr_chain = 1, curr_pos = 1;
 
void hld(int u, int p) {
    if (!chain_head[curr_chain]) {
        chain_head[curr_chain] = u;
    }
    chain_id[u] = curr_chain;
    pos[u] = curr_pos;
    curr_pos++;
    int next_node = 0;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (next_node == 0 or sz[next_node] < sz[v]) {
            next_node = v;
        }
    }
    if (next_node) {
        hld(next_node, u);
    }
    for (int v : adj[u]) {
        if (v == p or v == next_node) {
            continue;
        }
        curr_chain++;
        hld(v, u);
    }
}
 
int tree[MN*4];
 
void update(int node, int left, int right, int index, int value) {
    if (index < left or right < index) {
        return;
    }
    if (left == right) {
        tree[node] = value;
        return;
    }
    int mid = (left + right) >> 1;
    if (index <= mid) {
        update(node << 1, left, mid, index, value);
    }
    else {
        update(node << 1 | 1, mid + 1, right, index, value);
    }
    tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
}
 
int get(int node, int left, int right, int q_left, int q_right) {
    if (q_left > right or left > q_right) {
        return 0;
    }
    if (q_left <= left and right <= q_right) {
        return tree[node];
    }
    int mid = (left + right) >> 1;
    int left_node = 0, right_node = 0;
    if (q_left <= mid) {
        left_node = get(node << 1, left, mid, q_left, q_right);
    }
    if (mid <= q_right) {
        right_node = get(node << 1 | 1, mid + 1, right, q_left, q_right);
    }
    return max(left_node, right_node);
}
 
int node_lca(int u, int v) {
    if (u == v) {
        return u;
    }
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    int diff = depth[u] - depth[v];
    for (int i = LOG; i >= 0; --i) {
        if (diff & (1 << i)) {
            u = up[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = LOG; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}
 
int query(int u, int v) {
    int lca = node_lca(u, v);
    int ans = 0;
 
    while (chain_id[u] != chain_id[lca]) {
        ans = max(ans, get(1, 1, N, pos[chain_head[chain_id[u]]], pos[u]));
        u = par[chain_head[chain_id[u]]];
    }
 
    while (chain_id[v] != chain_id[lca]) {
        ans = max(ans, get(1, 1, N, pos[chain_head[chain_id[v]]], pos[v]));
        v = par[chain_head[chain_id[v]]];
    }
 
    if (depth[u] < depth[v]) {
        ans = max(ans, get(1, 1, N, pos[u], pos[v]));
    }
    else {
        ans = max(ans, get(1, 1, N, pos[v], pos[u]));
    }
 
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        cin >> val[i];
    }
    for (int i = 2; i <= N; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(up, -1, sizeof(up));
    dfs(1, 1);
    for (int j = 1; j <= LOG; ++j) {
        for (int i = 1; i <= N; ++i) {
            if (up[i][j - 1] != -1) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }
    hld(1, 1);
    for (int i = 1; i <= N; ++i) {
        update(1, 1, N, pos[i], val[i]);
    }
    while (Q--) {
        int c;
        cin >> c;
        if (c == 1) {
            int s, x;
            cin >> s >> x;
            update(1, 1, N, pos[s], x);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << query(a, b) << ' ';
        }
    }
    return 0;
}