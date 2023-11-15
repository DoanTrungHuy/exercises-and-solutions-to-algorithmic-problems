#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N;
const ll MN = 1e6 + 10;
ll a[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (ll i = 0; i < N; ++i) {
        cin >> a[i];
    }
    vector<ll> pref(N + 10, 0);
    vector<ll> suff(N + 10, 0);
    for (ll i = 1; i <= N; ++i) {
        pref[i] = __gcd(pref[i - 1], a[i - 1]);
    }
    for (ll i = N; i >= 1; --i) {
        suff[i] = __gcd(suff[i + 1], a[i - 1]);
    }
    ll ans = 0;
    for (ll i = 2; i <= N - 1; ++i) {
        ans = max(ans, __gcd(pref[i - 1], suff[i + 1]));
    }
    if (N == 1) {
        cout << 1000000000;
    }
    else if (N == 2) {
        cout << max(a[0], a[1]);
    }
    else {
        cout << ans;
    }
    return 0;
}