#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;
using ull = unsigned long long;
const ull BASE = 17, MOD = 1e9 + 7;
const int MN = 2e5 + 1;
ull p[MN];

struct Node {
    ull hash, len;

    Node(ull hash = 0, ull len = 0) {
        this->hash = hash, this->len = len;
    }

    friend Node operator + (const Node left_node, const Node right_node) {
        Node ans;
        ans.len = left_node.len + right_node.len;
        ans.hash = (left_node.hash*p[right_node.len] + right_node.hash) % MOD;
        return ans;
    }
};

class SegmentTree {
private:
    vector<Node> tree;
    int n;

public:
    SegmentTree() {

    }

    void resize(int n = 0) {
        tree.resize(4*n);
        this->n = n;
    }

    void update(int node, int left, int right, int index, ull value) {
        if (index < left or index > right) {
            return;
        }
        if (left == right) {
            tree[node] = {value, 1};
            return;
        }
        int mid = (left + right) / 2;
        update(node*2, left, mid, index, value);
        update(node*2 + 1, mid + 1, right, index, value);
        tree[node] = tree[node*2] + tree[node*2 + 1];
    }

    void update(int index, ull value) {
        update(1, 1, n, index, value);
    }

    Node get_node(int node, int left, int right, int q_left, int q_right) {
        if (q_left > right or left > q_right) {
            return {0, 0};
        }
        if (q_left <= left and right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) / 2;
        Node left_node = get_node(node*2, left, mid, q_left, q_right);
        Node right_node = get_node(node*2 + 1, mid + 1, right, q_left, q_right);
        return left_node + right_node;
    }

    Node get_node(int q_left, int q_right) {
        return get_node(1, 1, n, q_left, q_right);
    }
};

int main() {
    cin >> n >> m;
    cin >> s;

    p[0] = 1;

    for (int i = 1; i <= n; ++i) {
        p[i] = (p[i - 1]*BASE) % MOD;
    }

    SegmentTree st[2];
    st[0].resize(n);
    st[1].resize(n);

    for (int i = 1; i <= n; ++i) {
        st[0].update(i, s[i - 1] - 'a' + 1);
        st[1].update(i, s[n - i] - 'a' + 1);
    }

    while (m--) {
        int t;
        cin >> t;

        if (t == 1) {
            int k;
            char c;
            cin >> k >> c;
            st[0].update(k, c - 'a' + 1);
            st[1].update(n - k + 1, c - 'a' + 1);
        }
        else {
            int a, b;
            cin >> a >> b;
            if (st[0].get_node(a, b).hash == st[1].get_node(n - b + 1, n - a + 1).hash) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}