#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
const int MAXN = 2e5 + 1;
ll x[MAXN];
ll tree[MAXN*4] = {}, lazy[MAXN*4] = {};
int n, q;
 
void build(int node, int left, int right) {
    if (left == right) {
        tree[node] = x[left];
        return;
    }
    int mid = (right + left) / 2;
    build(2*node, left, mid);
    build(2*node + 1, mid + 1, right);
    tree[node] = tree[node*2] + tree[node*2 + 1];
}
 
void down(int node, int left, int right) {
    if (left > right or lazy[node] == 0) {
        return;
    }
    tree[node] = (right - left + 1)*lazy[node];
    if (left != right) {
        lazy[node*2] = lazy[node];
        lazy[node*2 + 1] = lazy[node];
    }
    lazy[node] = 0;
}
 
void update(int node, int left, int right, int qLeft, int qRight, ll value) {
    down(node, left, right);
    if (left > qRight or right < qLeft) {
        return;
    }
    if (qLeft <= left and right <= qRight) {
        lazy[node] = value;
        down(node, left, right);
        return;
    }
    int mid = (right + left) / 2;
    update(2*node, left, mid, qLeft, qRight, value);
    update(2*node + 1, mid + 1, right, qLeft, qRight, value);
    tree[node] = tree[node*2] + tree[node*2 + 1];
}
 
ll get_sum(int node, int left, int right, int qLeft, int qRight) {
    down(node, left, right);
    if (left > qRight or right < qLeft) {
        return 0;
    }
    if (qLeft <= left and right <= qRight) {
        return tree[node];
    }
    int mid = (right + left) / 2;
    ll left_node = get_sum(2*node, left, mid, qLeft, qRight);
    ll right_node = get_sum(2*node + 1, mid + 1, right, qLeft, qRight);
    return left_node + right_node;
}
 
int main() {
    cin >> n >> q;
    
    ll pref[n + 1] = {};
    
    for (int i = 0; i < n; ++i) {
        cin >> x[i + 1];
        pref[i + 1] = pref[i] + x[i + 1];
    }
    
    build(1, 1, n);
    
    ll ans[n + 1];
    using pii = pair<int, int>;
    unordered_map<int, vector<pii>> um;
    
    for (int i = 1; i <= q; ++i) {
        int a, b;
        cin >> a >> b;
        um[a].push_back({b, i});
    }
    
    stack<int> st;
    x[n + 1] = 2e9;
    st.push(n + 1);
    
    for (int a = n; a >= 1; --a) {
        while (x[st.top()] <= x[a]) {
            st.pop();
        }
        update(1, 1, n, a, st.top() - 1, x[a]);
        for (auto [b, i] : um[a]) {
            ans[i] = get_sum(1, 1, n, a, b) - (pref[b] - pref[a - 1]);
        }
        st.push(a);
    }
    
    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}