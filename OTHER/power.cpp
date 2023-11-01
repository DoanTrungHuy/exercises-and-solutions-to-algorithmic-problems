#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

int main() {
    ll T;
    cin >> T;
    for (ll test_case = 1; test_case <= T; ++test_case) {
        ll l, r;
        cin >> l >> r;
        ll ans = 1;
        for (ll k = 1; k <= 40; ++k) {
            ll left = 2;
            ll right = 1e12;
            ll x = 1;
            while (left <= right) {
                ll mid = (left + right) >> 1;
                ll fx = 1;
                for (ll i = 1; i <= k; ++i) {
                    fx *= mid;
                    if (fx > r) {
                        break;
                    }
                }
                if (fx >= l or fx >= r) {
                    x = mid;
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            ll fx = 1;
            for (ll i = 1; i <= k; ++i) {
                fx *= x;
                if (fx > r) {
                    break;
                }
            }
            if (l <= fx and fx <= r) {
                ans = max(ans, k);
            }
        }
        cout << "Case #" << test_case << ": " << ans << '\n';
    }
    return 0;
}