#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N;
const ll MN = 1e5 + 100;
ll a[MN];

int main() {
    ll T;
    cin >> T;
    while (T--) {
        cin >> N;
        for (ll i = 0; i < N; ++i) {
            cin >> a[i];
        }
        ll ans = a[0];
        for (ll i = 1; i < N; ++i) {
            ans &= a[i];
        }
        cout << ans << '\n';
    }
    return 0;
}