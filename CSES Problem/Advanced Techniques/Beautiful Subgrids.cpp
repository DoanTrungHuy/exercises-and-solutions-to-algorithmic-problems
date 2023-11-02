#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MN = 3e3 + 2;
ll N;
bitset<3000> a[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (ll i = 0; i < N; ++i) {
        cin >> a[i];
    }
    ll ans = 0;
    for (ll i = 0; i < N; ++i) {
        for (ll j = i + 1; j < N; ++j) {
            ll m = (a[i] & a[j]).count();
            ans += m * (m - 1) / 2;
        }
    }
    cout << ans;
    return 0;
}