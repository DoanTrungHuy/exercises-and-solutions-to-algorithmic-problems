#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, K;
const ll MN = 2e4 + 10;
bitset<31> a[MN];

int main() {
    cin >> N >> K;
    for (ll i = 0; i < N; ++i) {
        cin >> a[i];
    }
    ll ans = 31;
    for (ll i = 0; i < N; ++i) {
        for (ll j = i + 1; j < N; ++j) {
            ans = min(ans, (ll)((a[i] ^ a[j]).count()));
        }
    }
    cout << ans;
    return 0;
}