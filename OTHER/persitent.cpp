#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N, Q;
const ll MN = 2e5 + 100;
ll a[MN];
ll num_node = 0;

struct Node {
    ll sum, left, right;

    Node(ll sum = 0, ll left = 0, ll right = 0) {
        this->sum = sum;
        this->left = left, this->right = right;
    }
};

Node tree[40*MN];

ll update(ll old_node, ll left, ll right, ll index, ll value) {
    if (left == right) {
        tree[++num_node] = Node(value, 0, 0);
        return num_node;
    }
    ll curr = ++num_node;
    ll mid = (left + right) / 2;
    if (index <= mid) {
        tree[curr].left = update(tree[old_node].left, left, mid, index, value);
        tree[curr].right = tree[old_node].right;
    }
    else {
        tree[curr].right = update(tree[old_node].right, mid + 1, right, index, value);
        tree[curr].left = tree[old_node].left;
    }
    tree[curr].sum = tree[tree[curr].left].sum + tree[tree[curr].right].sum;
    return curr;
}

ll get_sum(ll node, ll left, ll right, ll q_left, ll q_right) {
    if (q_left > right or q_right < left) {
        return 0;
    }
    if (q_left <= left and right <= q_right) {
        return tree[node].sum;
    }
    ll mid = (left + right) >> 1;
    ll left_node = get_sum(tree[node].left, left, mid, q_left, q_right);
    ll right_node = get_sum(tree[node].right, mid + 1, right, q_left, q_right);
    return left_node + right_node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    vector<ll> ver = {1};
    for (ll i = 1; i <= N; ++i) {
        cin >> a[i];
        ver[0] = update(ver[0], 1, N, i, a[i]);
    }
    while (Q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll a, k, x;
            cin >> k >> a >> x;
            k--;
            ver[k] = update(ver[k], 1, N, a, x);
        }
        else if (t == 2) {
            ll a, b, k;
            cin >> k >> a >> b;
            k--;
            cout << get_sum(ver[k], 1, N, a, b) << '\n';
        }
        else {
            ll k;
            cin >> k;
            k--;
            ver.push_back(ver[k]);
        }
    }
    return 0;
}