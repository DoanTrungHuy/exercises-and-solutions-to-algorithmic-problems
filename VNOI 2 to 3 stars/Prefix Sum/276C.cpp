#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, q;
const ll MN = 2e5 + 5;
ll a[MN], c[MN];

int main()
{
    cin >> n >> q;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < q; ++i) {
        ll l, r;
        cin >> l >> r;
        c[l]++;
        c[r + 1]--;
    }
    for (ll i = 1; i <= n; ++i) {
        c[i] += c[i - 1];
    }
    sort(a + 1, a + n + 1);
    sort(c + 1, c + n + 1);
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        ans += a[i]*c[i];
    }
    cout << ans;
    return 0;
}