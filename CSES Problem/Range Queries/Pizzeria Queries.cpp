#include <bits/stdc++.h>
 
using namespace std;
 
class SegmentTree {
private:
    vector<int> tree;
    int n;
    
public:
    SegmentTree(int n = 0) {
        tree.resize((n + 1)*4, INT_MAX);
        this->n = n;
    }
    
    void update(int index, int value) {
        update(index, value, 1, 1, n);
    }
    
    void update(int index, int value, int node, int left, int right) {
        if (index < left or index > right) {
            return;
        }
        if (left == right) {
            tree[node] = value;
            return;
        }
        int mid = (left + right) / 2;
        update(index, value, node*2, left, mid);
        update(index, value, node*2 + 1, mid + 1, right);
        tree[node] = min(tree[node*2], tree[node*2 + 1]);
    }
    
    int getMin(int qLeft, int qRight) {
        return getMin(qLeft, qRight, 1, 1, n);
    }
    
    int getMin(int qLeft, int qRight, int node, int left, int right) {
        if (qRight < left or right < qLeft) {
            return INT_MAX;
        }
        if (qLeft <= left and right <= qRight) {
            return tree[node];
        }
        int mid = (left + right) / 2;
        int left_node = getMin(qLeft, qRight, node*2, left, mid);
        int right_node = getMin(qLeft, qRight, node*2 + 1, mid + 1, right);
        return min(left_node, right_node);
    }
};
 
int main()
{
    int n, q;
    cin >> n >> q;
    int p[n + 1];
    
    SegmentTree positive(n), negative(n);
    
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        positive.update(i, p[i] + i);
        negative.update(i, p[i] - i);
    }
    
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, x;
            cin >> k >> x;
            p[k] = x;
            positive.update(k, p[k] + k);
            negative.update(k, p[k] - k);
        }
        else {
            int k;
            cin >> k;
            int case1 = positive.getMin(min(k + 1, n), n) - k;
            int case2 = negative.getMin(1, max(1, k - 1)) + k;
            cout << min({p[k], case1, case2}) << '\n';
        }
    }
    return 0;
}