#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
 
using namespace std;
 
const int MN = 2e5 + 10;
int N, Q;
int val[MN];
vector<int> adj[MN];
int depth[MN], sz[MN], par[MN];
 
void dfs(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        par[v] = u;
        depth[v] = depth[u] + 1; 
        dfs(v, u);
        sz[u] += sz[v];
    }
}
 
int chain_head[MN], pos[MN];
int curr_pos = 1;
 
void hld(int u, int p, int h) {
    chain_head[u] = h;
    pos[u] = curr_pos;
    ++curr_pos;
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
        hld(next_node, u, h);
    }
    for (int v : adj[u]) {
        if (v == p or v == next_node) {
            continue;
        }
        hld(v, u, v);
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
    int mid = (left + right) / 2;
    if (index <= mid) {
        update(2*node, left, mid, index, value);
    }
    else {
        update(2*node + 1, mid + 1, right, index, value);
    }
    tree[node] = max(tree[2*node], tree[2*node + 1]);
}
 
int get(int node, int left, int right, int q_left, int q_right) {
    if (q_left > right or left > q_right) {
        return 0;
    }
    if (q_left <= left and right <= q_right) {
        return tree[node];
    }
    int mid = (left + right) / 2;
    int left_node = 0, right_node = 0;
    if (q_left <= mid) {
        left_node = get(2*node, left, mid, q_left, q_right);
    }
    if (mid <= q_right) {
        right_node = get(2*node + 1, mid + 1, right, q_left, q_right);
    }
    return max(left_node, right_node);
}

int query(int u, int v) {
    int ans = 0;
    while (chain_head[u] != chain_head[v]) {
        if (depth[chain_head[u]] < depth[chain_head[v]]) {
            swap(u, v);
        }
        ans = max(ans, get(1, 1, N, pos[chain_head[u]], pos[u]));
        u = par[chain_head[u]];
    }

    if (depth[u] > depth[v]) {
        swap(u, v);
    }

    return max(ans, get(1, 1, N, pos[u], pos[v]));
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
    dfs(1, 0);
    hld(1, 0, 1);
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