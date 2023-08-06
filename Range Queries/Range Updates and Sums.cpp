#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int MAXN = 2e5 + 5;
ll x[MAXN];
int n, q;
ll tree[4*MAXN], lazy[2][4*MAXN];
 
void down(int node, int left, int right) {
    if (left > right) {
        return;
    }
    
    if (lazy[1][node]) {
        tree[node] = (right - left + 1)*lazy[1][node];
    
        if (left != right) {
            lazy[0][2*node] = lazy[0][2*node + 1] = 0;
            lazy[1][2*node] = lazy[1][node];
            lazy[1][2*node + 1] = lazy[1][node];
        }
        
        lazy[1][node] = 0;
    }
    
    if (lazy[0][node]) {
        tree[node] += (right - left + 1)*lazy[0][node];
 
        if (left != right) {
            lazy[0][2*node] += lazy[0][node];
            lazy[0][2*node + 1] += lazy[0][node];
        }
        
        lazy[0][node] = 0;
    }
}
 
void update(int node, int left, int right, int qLeft, int qRight, ll value, int type) {
    down(node, left, right);
    if (right < qLeft or qRight < left) {
        return;
    }
    if (qLeft <= left and right <= qRight) {
        if (type == 1) {
            lazy[0][node] += value;
        }
        else if (type == 2) {
            lazy[1][node] = value;
            lazy[0][node] = 0;
        }
        down(node, left, right);
        return;
    }
    int mid = (left + right) / 2;
    update(node*2, left, mid, qLeft, qRight, value, type);
    update(node*2 + 1, mid + 1, right, qLeft, qRight, value, type);
    tree[node] = tree[node*2] + tree[node*2 + 1];
}
 
ll query(int node, int left, int right, int qLeft, int qRight) {
    down(node, left, right);
    if (right < qLeft or qRight < left) {
        return 0;
    }
    if (qLeft <= left and right <= qRight) {
        return tree[node];
    }
    int mid = (left + right) / 2;
    ll left_node = query(node*2, left, mid, qLeft, qRight);
    ll right_node = query(node*2 + 1, mid + 1, right, qLeft, qRight);
    return left_node + right_node;
}
 
int main()
{
    cin >> n >> q;
    
    for (int i = 0; i < 4*MAXN; ++i) {
        tree[i] = 0, lazy[0][i] = 0, lazy[1][i] = 0;
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        update(1, 1, n, i, i, x[i], 1);
    }
    
    while (q--) {
        int t;
        cin >> t;
        if (t == 1 or t == 2) {
            int a, b;
            ll u;
            cin >> a >> b >> u;
            update(1, 1, n, a, b, u, t);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << '\n';
        }
    }
    
    return 0;
}