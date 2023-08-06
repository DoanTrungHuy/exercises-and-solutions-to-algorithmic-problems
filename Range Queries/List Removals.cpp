#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 2e5 + 1;
int tree[MAXN*4];
 
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
    tree[node] = tree[node*2] + tree[node*2 + 1];
}
 
int query(int node, int left, int right, int size) {
    if (left == right) {
        return left;
    }
    int mid = (left + right) / 2;
    if (tree[node*2] >= size) {
        return query(node*2, left, mid, size);
    }
    return query(node*2 + 1, mid + 1, right, size - tree[node*2]);
}
 
int main()
{
    for (int i = 0; i < MAXN; ++i) {
        tree[i] = 0;
    }
    int n;
    cin >> n;
    int x[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        update(1, 1, n, i, 1);
    }
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        int j = query(1, 1, n, p);
        cout << x[j] << ' ';
        update(1, 1, n, j, 0);
    }
    return 0;
}