#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N, K;
const ll MN = 1e5 + 100;
ll a[MN];
const ll MOD = 1e9 + 7;

int main() {
    ll T;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        ll ans = 1;
        for (ll i = 0; i < K; ++i) {
            ans = (ans * N) % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}