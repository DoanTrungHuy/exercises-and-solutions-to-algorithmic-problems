#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n;
const ll MN = 5001;
ll a[MN], p[MN];

int main()
{
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    ll ans = 0;
    for (ll i = 2; i <= n; ++i) {
        for (ll j = 1; j <= n - i + 1; ++j) {
            ll l = j;
            ll r = j + i - 1;
            if ((p[r] + p[l - 1]) % 2 == 0) {
                ll k = lower_bound(p + l, p + r, (p[r] + p[l - 1]) / 2) - p;
                if (2*p[k] == (p[r] + p[l - 1])) {
                    ans = i;
                }
            }
        }
    }
    cout << ans;
    return 0;
}