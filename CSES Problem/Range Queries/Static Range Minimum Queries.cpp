#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int MAXN = 2e5 + 5;
ll x[MAXN];
int n, q;
ll tree[4*MAXN];
 
void update(int node, int left, int right, int index, ll value) {
    if (left > index or index > right) {
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
 
ll query(int node, int left, int right, int qLeft, int qRight) {
    if (right < qLeft or qRight < left) {
        return LLONG_MAX;
    }
    if (qLeft <= left and right <= qRight) {
        return tree[node];
    }
    int mid = (left + right) / 2;
    ll left_node = query(node*2, left, mid, qLeft, qRight);
    ll right_node = query(node*2 + 1, mid + 1, right, qLeft, qRight);
    return min(left_node, right_node);
}
 
int main()
{
    cin >> n >> q;
    
    for (int i = 0; i < 4*MAXN; ++i) {
        tree[i] = LLONG_MAX;
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        update(1, 1, n, i, x[i]);
    }
    
    while (q--) {
        int t, a, b;
        cin >> a >> b;
        cout << query(1, 1, n, a, b) << '\n';
    }
    
    return 0;
}