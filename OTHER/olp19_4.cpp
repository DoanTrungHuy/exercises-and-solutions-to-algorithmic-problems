#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, K;
const ll MN = 1e5 + 10;
ll d[MN];
ll pref[MN];

ll get(ll left, ll right) {
    return pref[right] - pref[left - 1];
}

int main() {
    cin >> N >> K;
    for (ll i = 0; i < N; ++i) {
        cin >> d[i];
    }
    for (ll i = 1; i <= N; ++i) {
        pref[i] = pref[i - 1] + d[i - 1];
    }
    ll ans = 0;
    for (ll i = 1; i <= N - K + 1; ++i) {
        ll left = i;
        ll right = i + K - 1;
        ll S = get(left, right);

        ll a = -1;
        {
            ll l = left;
            ll r = right - 2;

            while (l <= r) {
                ll mid = (l + r) / 2;

                if (2*get(l, mid) < S) {
                    a = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }

        if (a == -1) {
            continue;
        }

        ll b = -1;
        {
            ll l = a + 1;
            ll r = right - 1;

            while (l <= r) {
                ll mid = (l + r) / 2;

                if (2*get(a + 1, mid) < S) {
                    b = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }

        if (b == -1) {
            continue;
        }

        ll c = get(b + 1, right);
        if (2*c < S) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}