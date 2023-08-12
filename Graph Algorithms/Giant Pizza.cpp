#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 1;
vector<int> adj[MAXN];
int n, m;

int rev(int u) {
    if (u <= m) {
        return u + m;
    }
    else {
        return u - m;
    }
}

int num[MAXN], low[MAXN];
int step = 0;
int del[MAXN];
stack<int> st;
int par[MAXN];
int idSCC = 0;

void tarjan(int u) {
    num[u] = low[u] = ++step;
    st.push(u);

    for (int v : adj[u]) {
        if (del[v]) {
            continue;
        }
        if (num[v] == 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else {
            low[u] = min(low[u], num[v]);
        }
    }

    if (num[u] == low[u]) {
        idSCC++;
        int t;
        do {
            t = st.top();
            st.pop();
            par[t] = idSCC;
            del[t] = 1;
        } while (t != u);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        char op[2];
        int a, b;
        cin >> op[0] >> a >> op[1] >> b;
        if (op[0] == '-') {
            a += m;
        }
        if (op[1] == '-') {
            b += m;
        }
        adj[rev(a)].push_back(b);
        adj[rev(b)].push_back(a);
    }

    for (int i = 1; i <= m*2; ++i) {
        if (num[i] == 0) {
            tarjan(i);
        }
    }

    for (int i = 1; i <= m; ++i) {
        if (par[i] == par[i + m]) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    for (int i = 1; i <= m; ++i) {
        cout << (par[i] < par[i + m] ? '+' : '-') << ' ';
    }

    return 0;
}