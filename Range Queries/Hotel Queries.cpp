#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_NM = 2e5 + 1;
int h[MAX_NM], r[MAX_NM];
int tree[MAX_NM*4];
 
void update(int node, int left, int right, int index, int value) {
    if (index < left or index > right) {
        return;
    }
    if (left == right) {
        tree[node] = value;
        return;
    }
    int mid = (right + left) / 2;
    update(node*2, left, mid, index, value);
    update(node*2 + 1, mid + 1, right, index, value);
    tree[node] = max(tree[node*2], tree[node*2 + 1]);
}
 
int find(int node, int left, int right, int value) {
    if (left == right) {
        return left;
    }
    int mid = (right + left) / 2;
    if (tree[node*2] >= value) {
        return find(node*2, left, mid, value);
    }
    return find(node*2 + 1, mid + 1, right, value);
}
 
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        update(1, 1, n, i, h[i]);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> r[i];
        if (tree[1] < r[i]) {
            cout << 0 << ' ';
        }
        else {
            int j = find(1, 1, n, r[i]);
            cout << j << ' ';
            h[j] -= r[i];
            update(1, 1, n, j, h[j]);
        }
    }
    return 0;
}