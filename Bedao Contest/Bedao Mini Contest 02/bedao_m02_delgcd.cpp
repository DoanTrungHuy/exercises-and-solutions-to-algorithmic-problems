#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    // freopen("DELGCD.INP", "r", stdin);
    // freopen("DELGCD.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    ll a[N];
    ll ans = 0;
    for (ll i = 0; i < N; ++i) {
        cin >> a[i];
        ans = __gcd(ans, a[i]);
    }
    cout << (ans == 1 ? 0 : -1);
    return 0;
}