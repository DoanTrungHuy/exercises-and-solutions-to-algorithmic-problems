#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll M, N;
const ll MN = 105;
string s[MN];
const ll MN1D = MN*MN;
vector<ll> adj[MN1D];

ll cv_i1d(ll i, ll j) {
    return i*N + j;
}

bool is_range(ll i, ll j) {
    if (!(0 <= i and i < M and 0 <= j and j < N)) {
        return false;
    }
    return s[i][j] != '#';
}

ll num[MN1D], low[MN1D];
ll id_node = 0;
stack<ll> st;
bool del[MN1D];
ll scc = 0;
ll mapping_connected[MN1D], sum_of_connected[MN1D];

void dfs(ll u) {
    st.push(u);
    num[u] = low[u] = ++id_node;
    for (ll v : adj[u]) {
        if (del[v]) {
            continue;
        }
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        }
        else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (num[u] == low[u]) {
        ll v;
        ++scc;
        do {
            v = st.top();
            st.pop();
            mapping_connected[v] = scc;
            if (isdigit(s[v / N][v % N])) {
                sum_of_connected[scc] += s[v / N][v % N] - '0';
            }
            del[v] = true;
        } while (v != u);
    }
}

map<ll, set<ll>> mpc_adj;
ll indegree[MN1D];
ll memo[MN1D];

ll dag_dfs(ll u) {
    if (memo[u] != -1) {
        return memo[u];
    }
    ll max_prev = 0;
    for (ll v : mpc_adj[u]) {
        max_prev = max(max_prev, dag_dfs(v));
    }
    return memo[u] = max_prev + sum_of_connected[u];
}

int main() {
    cin >> M >> N;
    for (ll i = 0; i < M; ++i) {
        cin >> s[i];
    }
    for (ll i = 0; i < M; ++i) {
        for (ll j = 0; j < N; ++j) {
            if (is_range(i, j + 1)) {
                adj[cv_i1d(i, j)].push_back(cv_i1d(i, j + 1));
            }
            if (is_range(i + 1, j)) {
                adj[cv_i1d(i, j)].push_back(cv_i1d(i + 1, j));
            }
            if (s[i][j] == 'N' and is_range(i - 1, j)) {
                adj[cv_i1d(i, j)].push_back(cv_i1d(i - 1, j));
            }
            if (s[i][j] == 'W' and is_range(i, j - 1)) {
                adj[cv_i1d(i, j)].push_back(cv_i1d(i, j - 1));
            }
        }
    }
    for (ll u = 0; u < M*N; ++u) {
        if (num[u] == 0 and is_range(u / N, u % N)) {
            dfs(u);
        }
    }
    for (ll u = 0; u < M*N; ++u) {
        for (ll v : adj[u]) {
            if (mapping_connected[u] != mapping_connected[v]) {
                mpc_adj[mapping_connected[u]].insert(mapping_connected[v]);
                indegree[mapping_connected[v]]++;
            }
        }
    }
    memset(memo, -1, sizeof(memo));
    ll res = 0;
    for (ll u = 1; u <= scc; ++u) {
        if (indegree[u] == 0) {
            res = max(res, dag_dfs(u));
        }
    }
    cout << res;
    return 0;
}