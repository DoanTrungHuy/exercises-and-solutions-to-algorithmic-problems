#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q;
const ll MN = 2e5 + 10;
ll tree[MN*4], lazy[MN*4];
ll a[MN];

void down(ll node, ll left, ll right) {
    if (left > right or lazy[node] == 0) {
        return;
    }
    tree[node] = lazy[node];
    if (left != right) {
        lazy[node*2] = lazy[node];
        lazy[node*2 + 1] = lazy[node];
    }
    lazy[node] = 0;
}

void update(ll node, ll left, ll right, ll q_left, ll q_right, ll value) {
    down(node, left, right);
    if (left > q_right or right < q_left) {
        return;
    }
    if (q_left <= left and right <= q_right) {
        lazy[node] = value;
        down(node, left, right);
        return;
    }
    ll mid = (left + right) >> 1;
    update(node*2, left, mid, q_left, q_right, value);
    update(node*2 + 1, mid + 1, right, q_left, q_right, value);
    if (tree[node*2] != 0) {
        tree[node] = tree[node*2];
    }
    if (tree[node*2 + 1] != 0) {
        tree[node] = tree[node*2 + 1];
    }
}

ll get_val(ll node, ll left, ll right, ll q_left, ll q_right) {
    down(node, left, right);
    if (left > q_right or right < q_left) {
        return 0;
    }
    if (q_left <= left and right <= q_right) {
        down(node, left, right);
        return tree[node];
    }
    ll mid = (left + right) >> 1;
    ll left_node = get_val(node*2, left, mid, q_left, q_right);
    ll right_node = get_val(node*2 + 1, mid + 1, right, q_left, q_right);
    if (left_node != 0) {
        return left_node;
    }
    return right_node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;
    
    for (ll i = 0; i < q; ++i) {
        ll l, r, c;
        cin >> l >> r >> c;
        l--, r--;
        update(1, 0, n - 1, l, r, c);
    }
    for (ll i = 0; i < n; ++i) {
        cout << get_val(1, 0, n - 1, i, i) << '\n';
    }
    return 0;
}