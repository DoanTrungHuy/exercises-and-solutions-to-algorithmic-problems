#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MN = 2e5 + 10;
ll N, Q;
vector<ll> adj[MN];
ll inp[MN], out[MN];
ll val[MN];
ll id_node = 0;

void dfs(ll u, ll p) {
    inp[u] = ++id_node;
    for (ll v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
    }
    out[u] = id_node;
}

ll tree[4*MN];

void update(ll node, ll left, ll right, ll index, ll value) {
    if (index < left or right < index) {
        return;
    }
    if (left == right) {
        tree[node] = value;
        return;
    }
    ll mid = (left + right) / 2;
    update(node*2, left, mid, index, value);
    update(node*2 + 1, mid + 1, right, index, value);
    tree[node] = tree[node*2] + tree[node*2 + 1];
}

ll get_sum(ll node, ll left, ll right, ll q_left, ll q_right) {
    if (q_left > right or q_right < left) {
        return 0;
    }
    if (q_left <= left and right <= q_right) {
        return tree[node];
    }
    ll mid = (left + right) / 2;
    ll left_node = get_sum(node*2, left, mid, q_left, q_right);
    ll right_node = get_sum(node*2 + 1, mid + 1, right, q_left, q_right);
    return left_node + right_node;
}

int main() {
    cin >> N >> Q;
    for (ll i = 1; i <= N; ++i) {
        cin >> val[i];
    }
    for (ll i = 1; i <= N - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    for (ll i = 1; i <= N; ++i) {
        update(1, 1, N, inp[i], val[i]);
    }
    while (Q--) {
        ll choose;
        cin >> choose;
        if (choose == 1) {
            ll s, x;
            cin >> s >> x;
            update(1, 1, N, inp[s], x);
        }
        else {
            ll s;
            cin >> s;
            cout << get_sum(1, 1, N, inp[s], out[s]) << '\n';
        }
    }
    return 0;
}