#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MN = 2e5 + 1;
ll N, Q;
const ll LOG = ceil(log2(MN));
ll up[MN][LOG + 1];

int main() {
    cin >> N >> Q;
    memset(up, -1, sizeof(up));
    for (ll i = 2; i <= N; ++i) {
        ll parent;
        cin >> parent;
        up[i][0] = parent;
    }
    for (ll j = 1; j <= LOG; ++j) {
        for (ll i = 1; i <= N; ++i) {
            if (up[i][j - 1] != -1) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }
    const auto jump = [&](ll u, ll k) -> ll {
        for (ll i = LOG; i >= 0; --i) {
            if (k & (1 << i)) {
                u = up[u][i];
                if (u == -1) {
                    break;
                }
            }
        }
        return u;
    };
    while (Q--) {
        ll x, k;
        cin >> x >> k;
        cout << jump(x, k) << '\n';
    }
    return 0;
}