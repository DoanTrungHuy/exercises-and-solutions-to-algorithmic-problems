#include <bits/stdc++.h>
 
using namespace std;
 
int n, q;
const int MAXN = 2e5 + 5;
int x[MAXN], tree[4*MAXN];
 
void update(int node, int left, int right, int index, int value) {
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
    tree[node] = tree[node*2] + tree[node*2 + 1];
}
 
int query(int node, int left, int right, int qLeft, int qRight) {
    if (right < qLeft or qRight < left) {
        return 0;
    }
    if (qLeft <= left and right <= qRight) {
        return tree[node];
    }
    int mid = (left + right) / 2;
    int left_node = query(node*2, left, mid, qLeft, qRight);
    int right_node = query(node*2 + 1, mid + 1, right, qLeft, qRight);
    return left_node + right_node;
}
 
 
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    int ans[q + 1];
    unordered_map<int, vector<array<int, 2>>> um;
    for (int i = 1; i <= q; ++i) {
        int a, b;
        cin >> a >> b;
        um[b].push_back({a, i});
    }
    unordered_map<int, int> last_index;
    for (int b = 1; b <= n; ++b) {
        update(1, 1, n, b, 1);
        if (last_index.find(x[b]) != last_index.end()) {
            update(1, 1, n, last_index[x[b]], 0);
        }
        last_index[x[b]] = b;
        for (array<int, 2> arr : um[b]) {
            int a = arr[0];
            int i = arr[1];
            ans[i] = query(1, 1, n, a, b);
        }
    }
    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}