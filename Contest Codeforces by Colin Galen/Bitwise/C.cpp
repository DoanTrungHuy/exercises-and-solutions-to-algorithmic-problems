#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N;
const ll MN = 1e5 + 100;
ll a[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll T;
    cin >> T;
    while (T--) {
        cin >> N;
        for (ll i = 0; i < N; ++i) {
            cin >> a[i];
        }
        unordered_map<ll, ll> cnt;
        for (ll i = 0; i < N; ++i) {
            cnt[64 - __builtin_clzll(a[i])]++;
        }
        ll ans = 0;
        for (const auto [v, c] : cnt) {
            ans += c * (c - 1) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}