#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;
using ll = long long;
int n, m, q;
ll dist[MAXN][MAXN];

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = LLONG_MAX;
        }
    }

    for (int i = 1; i <= m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        dist[a][b] = dist[b][a] = min({1LL*w, dist[a][b], dist[b][a]});
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    dist[i][j] = 0;
                }
                else {
                    if (dist[i][k] != LLONG_MAX and dist[k][j] != LLONG_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            } 
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << (dist[a][b] == LLONG_MAX ? -1 : dist[a][b]) << '\n';
    }

    return 0;
}