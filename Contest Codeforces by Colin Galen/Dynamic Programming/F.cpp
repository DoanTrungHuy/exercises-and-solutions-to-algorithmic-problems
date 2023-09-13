#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll n, k;

ll calc_per(vector<ll> &val, vector<ll> &idx) {
    ll cnt_way = 0;
    ll m = idx.size();
    do {
        ll cnt_diff = 0;
        for (ll i = 0; i < m; ++i) {
            if (val[idx[i]] != i) {
                cnt_diff++;
            }
            else {
                break;
            }
        }
        if (cnt_diff == m) {
            cnt_way++;
        }
    } while (next_permutation(idx.begin(), idx.end()));
    return cnt_way;
}

int main() {
    cin >> n >> k;

    ll f[n + 1][k + 1];
    memset(f, 0, sizeof(f));

    for (ll i = 0; i <= n; ++i) {
        for (ll j = 0; j <= k; ++j) {
            if (j == 0) {
                f[i][j] = 1;
            }
            else if (i == 0) {
                f[i][j] = 0;
            }
            else {
                f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
            }
        }
    }
    
    ll ans = 0;

    for (ll i = 1; i <= k; ++i) {
        vector<ll> val(i), idx(i);

        for (ll j = 0; j < i; ++j) {
            val[j] = j;
            idx[j] = j;
        }

        ans += calc_per(val, idx)*f[n][i];
    }

    cout << ans + 1;
    
    return 0;
}