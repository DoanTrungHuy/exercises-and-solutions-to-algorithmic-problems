#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MN = 1e5 + 10;
int n, m, q;
int a[MN], b[MN], c[MN];
int tree[4*MN];

void update(int node, int left, int right, int index, int value) {
    if (index < left or index > right) {
        return;
    }
    if (left == right) {
        tree[node] = value;
        return;
    }
    int mid = (left + right) / 2;
    update(node*2, left, mid, index, value);
    update(node*2 + 1, mid + 1, right, index, value);
    tree[node] = min(tree[node*2], tree[node*2 + 1]);
}

int get_min(int node, int left, int right, int q_left, int q_right) {
    if (q_left > right or q_right < left) {
        return INT_MAX;
    }
    if (q_left <= left and right <= q_right) {
        return tree[node];
    }
    int mid = (left + right) / 2;
    int left_node = get_min(node*2, left, mid, q_left, q_right);
    int right_node = get_min(node*2 + 1, mid + 1, right, q_left, q_right);
    return min(left_node, right_node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);  
    cin >> n >> m >> q;
    for (int i = 0; i < 4*MN; ++i) {
        tree[i] = INT_MAX;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        c[i] = INT_MAX;
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(b, b + m);
    for (int i = 0; i < n; ++i) {
        auto j = lower_bound(b, b + m, a[i]) - b;
        if (j != m) {
            c[i] = min(c[i], abs(a[i] - b[j]));
        }
        if (j > 0) {
            c[i] = min(c[i], abs(a[i] - b[j - 1]));
        }
        if (j + 1 < m) {
            c[i] = min(c[i], abs(a[i] - b[j + 1]));
        }
        update(1, 0, n - 1, i, c[i]);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << get_min(1, 0, n - 1, l, r) << '\n';
    }
    return 0;
}