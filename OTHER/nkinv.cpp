#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N;
const ll MN = 6e4 + 100;
ll a[MN];
ll tree[4*MN];

void update(ll node, ll left, ll right, ll index, ll value) {
    if (index < left or index > right) {
        return;
    }
    if (left == right) {
        tree[node] += value;
        return;
    }
    ll mid = (left + right) / 2;
    update(node*2, left, mid, index, value);
    update(node*2 + 1, mid + 1, right, index, value);
    tree[node] = tree[node*2] + tree[node*2 + 1];
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
    return left_node + right_node;
}

const ll MAXV = 6e4;

int main() {
    cin >> N;
    ll ans = 0;
    for (ll i = 0; i < N; ++i) {
        cin >> a[i];
        ans += get(1, 0, MAXV, a[i] + 1, MAXV);
        update(1, 0, MAXV, a[i], 1);
    }
    cout << ans;
    return 0;
}