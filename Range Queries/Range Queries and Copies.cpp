#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 2e5 + 1;
using ll = long long;
ll t[MAXN];
 
struct Node {
    int left, right;
    ll sum;
    
    Node(ll sum = 0, int left = 0, int right = 0) {
        this->sum = sum;
        this->left = left, this->right = right;
    }
};
 
Node tree[MAXN*40];
 
int nNode = 0;
 
int update(int oldNode, int left, int right, int index, ll value) {
    if (left == right) {
        tree[++nNode] = Node(value, 0, 0);
        return nNode;
    }
    int curr = ++nNode;
    int mid = (right + left) / 2;
    if (index <= mid) {
        tree[curr].left = update(tree[oldNode].left, left, mid, index, value);
        tree[curr].right = tree[oldNode].right;
    }
    else {
        tree[curr].right = update(tree[oldNode].right, mid + 1, right, index, value);
        tree[curr].left = tree[oldNode].left;
    }
    tree[curr].sum = tree[tree[curr].left].sum + tree[tree[curr].right].sum;
    return curr;
}
 
ll get_sum(int node, int left, int right, int qLeft, int qRight) {
    if (right < qLeft or qRight < left) {
        return 0;
    }
    if (qLeft <= left and right <= qRight) {
        return tree[node].sum;
    }
    int mid = (right + left) / 2;
    ll left_node = get_sum(tree[node].left, left, mid, qLeft, qRight);
    ll right_node = get_sum(tree[node].right, mid + 1, right, qLeft, qRight);
    return left_node + right_node;
}
 
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> ver = {1};
    
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
        ver[0] = update(ver[0], 1, n, i, t[i]);
    }
    
    while (q--) {
        int t;
        cin >> t;
        
        if (t == 1) {
            int k, a, x;
            cin >> k >> a >> x;
            k--;
            ver[k] = update(ver[k], 1, n, a, x);
        }
        else if (t == 2) {
            int a, b, k;
            cin >> k >> a >> b;
            k--;
            cout << get_sum(ver[k], 1, n, a, b) << '\n';
        }
        else {
            int k;
            cin >> k;
            k--;
            ver.push_back(ver[k]);
        }
    }
    return 0;
}