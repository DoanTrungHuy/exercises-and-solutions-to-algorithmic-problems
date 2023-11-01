#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const ll MN = 6e5 + 10;
ll N, M, K;
map<pii, ll> events;
bool query[MN];

struct DSU {
    vector<ll> parent, rank;
    stack<pii> sav_par, sav_rnk;
    ll component = 0;
    ll curr = 0;

    DSU(ll n = 0) {
        this->component = n;
        parent.resize(n + 1);
        rank.resize(n + 1, 1);

        for (ll i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    ll find(ll u) {
        if (u != parent[u]) {
            return find(parent[u]);
        }
        return parent[u];
    }

    bool _union(ll u, ll v) {
        u = find(u);
        v = find(v);

        if (u == v) {
            return false;
        }

        if (rank[u] < rank[v]) {
            swap(u, v);
        }

        component--;
        curr++;

        sav_par.push({v, parent[v]});
        sav_rnk.push({u, rank[u]});

        parent[v] = u;
        rank[u] += rank[v];

        return true;
    }

    void rollback(ll prev) {
        while (prev < curr) {
            const auto [v, pv] = sav_par.top();
            sav_par.pop();
            parent[v] = pv;

            const auto [u, ru] = sav_rnk.top();
            sav_rnk.pop();
            rank[u] = ru;

            component++;
            curr--;
        }
    }
} dsu;

struct SegmentTree {
    vector<vector<pii>> tree;
    vector<ll> ans;

    SegmentTree(ll n = 0) {
        tree.resize(4*n + 1);
    }

    void update(ll node, ll left, ll right, ll q_left, ll q_right, pii value) {
        if (q_left > right or left > q_right) {
            return;
        }
        if (q_left <= left and right <= q_right) {
            tree[node].push_back(value);
            return;
        }
        ll mid = (left + right) >> 1;
        update(node*2, left, mid, q_left, q_right, value);
        update(node*2 + 1, mid + 1, right, q_left, q_right, value);
    }

    void dfs(ll node, ll left, ll right) {
        ll prev = dsu.curr;
        for (const auto [u, v] : tree[node]) {
            dsu._union(u, v);
        }
        if (left == right) {
            if (query[left]) {
                ans.push_back(dsu.component);
            }
        }
        else {
            ll mid = (left + right) >> 1;
            dfs(node*2, left, mid);
            dfs(node*2 + 1, mid + 1, right);
        }
        dsu.rollback(prev); 
    }
};

int main() {
    cin >> N >> M >> K;
    DSU tmp(N);
    dsu = tmp;
    for (ll i = 0; i < M; ++i) {
        ll u, v;
        cin >> u >> v;
        if (u > v) {
            swap(u, v);
        }
        events[{u, v}] = 0;
    }
    memset(query, false, sizeof(query));
    query[1] = true;
    SegmentTree st(2*K + 1);
    for (ll i = 2; i <= 2*K + 1; ++i) {
        ll c, u, v;
        cin >> c >> u >> v;
        if (u > v) {
            swap(u, v);
        }
        if (c == 1) {
            events[{u, v}] = i;
        }
        else {
            st.update(1, 0, 2*K + 1, events[{u, v}], i, {u, v});
            if (events.count({u, v})) {
                events.erase({u, v});
            }
        }
        query[++i] = true;
    }
    for (const auto [v, i] : events) {
        st.update(1, 0, 2*K + 1, i, 2*K + 1, v);
    }
    st.dfs(1, 0, 2*K + 1);
    for (ll val : st.ans) {
        cout << val << ' ';
    }
    return 0;
}