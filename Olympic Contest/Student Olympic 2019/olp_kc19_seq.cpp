#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, K;
const ll MN = 1e5 + 10;
ll a[MN], b[MN];
ll tree[4*MN];

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
    tree[node] = __gcd(tree[node*2], tree[node*2 + 1]);
}

ll get_gcd(ll node, ll left, ll right, ll q_left, ll q_right) {
    if (q_left > right or q_right < left) {
        return 0;
    }
    if (q_left <= left and right <= q_right) {
        return tree[node];
    }
    ll mid = (left + right) / 2;
    ll left_node = get_gcd(node*2, left, mid, q_left, q_right);
    ll right_node = get_gcd(node*2 + 1, mid + 1, right, q_left, q_right);
    return __gcd(left_node, right_node);
}

int main() {
    cin >> N >> K;
    for (ll i = 0; i < N; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < N; ++i) {
        cin >> b[i];
    }
    for (ll i = 0; i < N; ++i) {
        update(1, 0, N - 1, i, abs(a[i] - b[i]));
    }
    while (K--) {
        ll L, R;
        cin >> L >> R;
        cout << get_gcd(1, 0, N - 1, L - 1, R - 1) << '\n';
    }
    return 0;
}