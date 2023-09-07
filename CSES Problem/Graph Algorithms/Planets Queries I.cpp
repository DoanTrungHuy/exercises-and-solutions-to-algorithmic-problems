#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 1;
int n, q;
const int LOG = 30;
int t[MAXN], par[MAXN][LOG];

int query(int x, int k) {
    for (int i = LOG; i >= 0; --i) {
        if (k & (1 << i)) {
            x = par[x][i];
        }
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    for (int u = 1; u <= n; ++u) {
        par[u][0] = t[u];
    }

    for (int i = 1; i < LOG; ++i) {
        for (int u = 1; u <= n; ++u) {
            par[u][i] = par[par[u][i - 1]][i - 1];
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << query(x, k) << '\n';
    }

    return 0;
}