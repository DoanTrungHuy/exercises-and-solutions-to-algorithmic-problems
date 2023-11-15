#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, M;
const ll MN = 55;
ll table[MN][MN];

int main() {
    cin >> N >> M;
    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j < M; ++j) {
            cin >> table[i][j];
        }
    }
    ll ans = 0;
    for (ll i = 0; i < N; ++i) {
        ll cnt_cb = 0, cnt_cw = 0;
        for (ll j = 0; j < M; ++j) {
            if (table[i][j] == 0) {
                cnt_cw++;
            }
            else {
                cnt_cb++;
            }
        }
        ans += (1LL << cnt_cb) - 1;
        ans += (1LL << cnt_cw) - 1;
    }
    for (ll j = 0; j < M; ++j) {
        ll cnt_cb = 0, cnt_cw = 0;
        for (ll i = 0; i < N; ++i) {
            if (table[i][j] == 0) {
                cnt_cw++;
            }
            else {
                cnt_cb++;
            }
        }
        ans += (1LL << cnt_cb) - 1;
        ans += (1LL << cnt_cw) - 1;
    }
    cout << ans - N*M;
    return 0;
}