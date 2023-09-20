#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n;
const ll MN = 1e5;
ll b[MN], c[MN];

int main()
{
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
    }
    sort(b, b + n);
    ll ans = INT_MAX;
    for (ll i = 0; i < n; ++i) {
        ll j = lower_bound(b, b + n, -c[i]) - b;
        if (0 <= j and j < n) {
            ans = min(ans, abs(c[i] + b[j]));
        }
        if (0 <= j + 1 and j + 1 < n) {
            ans = min(ans, abs(c[i] + b[j + 1]));
        }
        if (0 <= j - 1 and j - 1 < n) {
            ans = min(ans, abs(c[i] + b[j - 1]));
        }
    }
    cout << ans;
    return 0;
}