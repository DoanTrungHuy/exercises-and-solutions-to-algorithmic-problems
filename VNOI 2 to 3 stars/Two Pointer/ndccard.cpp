#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, x;
const ll MN = 1e6;
ll a[MN];

int main()
{
    cin >> n >> x;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll ans = INT_MIN;
    for (ll i = 0; i < n; ++i) {
        ll j = i + 1, k = n - 1;
        ll new_x = x - a[i];
        while (j < k) {
            if (a[j] + a[k] == new_x) {
                ans = max(ans, a[i] + a[j] + a[k]);
                j++, k--;
            }
            else if (a[j] + a[k] < new_x) {
                ans = max(ans, a[i] + a[j] + a[k]);
                j++;
            }
            else {
                k--;
            }
        }
    }
    cout << ans;
    return 0;
}