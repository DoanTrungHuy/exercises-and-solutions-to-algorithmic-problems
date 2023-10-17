#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, E;
const ll MN = 1e5 + 5;
vector<ll> adj[MN];
ll inp[MN], low[MN], out[MN];
bool joint[MN];
ll id_node = 0;

const ll LOG = ceil(log2(MN));
ll par[MN][LOG + 1];
ll depth[MN];

void dfs(ll u, ll p) {
    inp[u] = low[u] = ++id_node;
    ll child = 0;
    for (ll v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (inp[v]) {
            low[u] = min(low[u], inp[v]);
        }
        else {
            par[v][0] = u;
            depth[v] = depth[u] + 1;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            child++;
            if (u != 1 and child > 1) {
                joint[u] = true;
            }
            else if (low[v] >= inp[u]) {
                joint[u] = true;
            }
        }
    }
    out[u] = ++id_node;
}

bool is_in_subtree(ll u, ll root) {
    return inp[root] <= inp[u] and inp[u] <= out[root];
}

string solve_1(ll A, ll B, ll G1, ll G2) {
    if (inp[G1] > inp[G2]) {
        swap(G1, G2);
    }
    if (inp[G1] >= low[G2]) {
        return "yes";
    }
    if (is_in_subtree(A, G2) and !is_in_subtree(B, G2)) {
        return "no";
    }
    if (!is_in_subtree(A, G2) and is_in_subtree(B, G2)) {
        return "no";
    }
    return "yes";
}

ll find_parent(ll node, ll C) {
    for (ll i = LOG; i >= 0; --i) {
        if (depth[par[node][i]] > depth[C]) {
            node = par[node][i];
        }
    }
    return node;
}

string solve_2(ll A, ll B, ll C) {
    if (!joint[C]) {
        return "yes";
    }
    ll pA = 0;
    ll pB = 0;
    if (is_in_subtree(A, C)) {
        pA = find_parent(A, C);
    }
    if (is_in_subtree(B, C)) {
        pB = find_parent(B, C);
    }
    if ((!pA and !pB) or (pA == pB)) {
        return "yes";
    }
    if (!pA and low[pB] < inp[C]) {
        return "yes";
    }
    if (!pB and low[pA] < inp[C]) {
        return "yes";
    }
    if (pA and pB and low[pA] < inp[C] and low[pB] < inp[C]) {
        return "yes";
    }
    return "no";
}

int main() {
    cin >> N >> E;
    for (ll i = 0; i < E; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(joint, false, sizeof(joint));
    memset(par, -1, sizeof(par));
    memset(depth, 0, sizeof(depth));
    dfs(1, -1);
    for (ll j = 1; j <= LOG; ++j) {
        for (ll i = 1; i <= N; ++i) {
            if (par[i][j - 1] != -1) {
                par[i][j] = par[par[i][j - 1]][j - 1];
            }
        }
    }
    ll q;
    cin >> q;
    while (q--) {
        ll query;
        cin >> query;
        if (query == 1) {
            ll A, B, G1, G2;
            cin >> A >> B >> G1 >> G2;
            cout << solve_1(A, B, G1, G2) << '\n';
        }
        else {
            ll A, B, C;
            cin >> A >> B >> C;
            cout << solve_2(A, B, C) << '\n';
        }
    }
    return 0;
}