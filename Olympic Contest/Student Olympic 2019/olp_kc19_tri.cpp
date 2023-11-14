#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, K;
const ll MN = 1e5 + 10;
ll d[MN], pref[MN];

ll get_sum(ll l, ll r) {
    if (l > r) {
        return 0;
    }
    return pref[r + 1] - pref[l];
}

int main() {
    cin >> N >> K;
    memset(pref, 0, sizeof(pref));
    for (ll i = 0; i < N; ++i) {
        cin >> d[i];
        pref[i + 1] = pref[i] + d[i];
    }
    ll ans = 0;
    for (ll i = 0; i < N - K + 1; ++i) {
        ll s = get_sum(i, i + K - 1);
        ll a = -1;
        {
            ll left = i;
            ll right = i + K - 3;
            while (left <= right) {
                ll mid = (left + right) / 2;
                if (2 * get_sum(i, mid) < s) {
                    a = mid;
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        if (a == -1) {
            continue;
        }
        ll b = -1;
        {
            ll left = a + 1;
            ll right = i + K - 2;
            while (left <= right) {
                ll mid = (left + right) / 2;
                if (2 * get_sum(a + 1, mid) < s) {
                    b = mid;
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        if (b == -1) {
            continue;
        }
        if (2*get_sum(b + 1, i + K - 1) >= s) {
            continue;
        }
        ans++;
    }
    cout << ans;
    return 0;
}