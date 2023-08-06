#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int MAXN = 2e5 + 1;
ll t[MAXN], tree[MAXN*4] = {};
ll lazy[2][MAXN*4] = {};
 
void build(int node, int left, int right) {
    if (left == right) {
        tree[node] = t[left];
        return;
    }
    int mid = (right + left) / 2;
    build(node*2, left, mid);
    build(node*2 + 1, mid + 1, right);
    tree[node] = tree[node*2] + tree[node*2 + 1];
}
 
ll aritmeti(ll num) {
    return num*(num + 1) / 2;
}
 
void down(int node, int left, int right) {
    if (left > right) {
        return;
    }
    
    tree[node] += (right - left + 1) * lazy[0][node];
    tree[node] += (aritmeti(right) - aritmeti(left - 1)) * lazy[1][node];
    
    if (left != right) {
        lazy[0][node*2] += lazy[0][node];
        lazy[0][node*2 + 1] += lazy[0][node];
        
        lazy[1][node*2] += lazy[1][node];
        lazy[1][node*2 + 1] += lazy[1][node];
    }
    
    lazy[0][node] = 0;
    lazy[1][node] = 0;
}
 
void update(int node, int left, int right, int qLeft, int qRight) {
    down(node, left, right);
    if (right < qLeft or left > qRight) {
        return;
    }
    if (qLeft <= left and right <= qRight) {
        lazy[0][node] += 1 - qLeft;
        lazy[1][node] += 1;
        down(node, left, right);
        return;
    }
    int mid = (right + left) / 2;
    update(node*2, left, mid, qLeft, qRight);
    update(node*2 + 1, mid + 1, right, qLeft, qRight);
    tree[node] = tree[node*2] + tree[node*2 + 1];
}
 
ll get_sum(int node, int left, int right, int qLeft, int qRight) {
    down(node, left, right);
    if (right < qLeft or left > qRight) {
        return 0LL;
    }
    if (qLeft <= left and right <= qRight) {
        return tree[node];
    }
    int mid = (right + left) / 2;
    ll left_node = get_sum(node*2, left, mid, qLeft, qRight);
    ll righth_node = get_sum(node*2 + 1, mid + 1, right, qLeft, qRight);
    return left_node + righth_node;
}
 
int main()
{
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }
    
    build(1, 1, n);
    
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            update(1, 1, n, a, b);
        }
        else {
            cout << get_sum(1, 1, n, a, b) << '\n';
        }
    }
    return 0;
}