#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m, q;
const ll MN = 501;
ll grid[MN][MN];

int main() {
    cin >> n >> m >> q;

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    ll f[MN][MN];
    memset(f, 0, sizeof(f));
    ll max_[MN];
    memset(max_, 0, sizeof(max_));

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (j == 0 or grid[i][j] == 0) {
                f[i][j] = grid[i][j];
            }
            else {
                f[i][j] = f[i][j - 1] + 1;
            }
            max_[i] = max(max_[i], f[i][j]);
        }
    }

    while (q--) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        grid[x][y] ^= 1;
        ll i = x;
        memset(f[i], 0, sizeof(f[i]));
        max_[i] = 0;
        for (ll j = 0; j < m; ++j) {
            if (j == 0 or grid[i][j] == 0) {
                f[i][j] = grid[i][j];
            }
            else {
                f[i][j] = f[i][j - 1] + 1;
            }
            max_[i] = max(max_[i], f[i][j]);
        }
        ll ans = 0LL;
        for (int k = 0; k < n; ++k) {
            ans = max(ans, max_[k]);
        }
        cout << ans << '\n';
    }

	return 0;
}