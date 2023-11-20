#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, M;
const ll MN = 1e5 + 1000;
ll a[MN];

ll f(ll x) {
    ll left_max[N], right_max[N];
    ll b[N];
    for (ll i = 0; i < N; ++i) {
        b[i] = max(a[i], x);
    }
    left_max[0] = b[0];
    for (ll i = 1; i < N; ++i) {
        left_max[i] = max(left_max[i - 1], b[i]);
    }
    right_max[N - 1] = b[N - 1];
    for (ll i = N - 2; i >= 0; --i) {
        right_max[i] = max(right_max[i + 1], b[i]);
    }
    ll remain_water = 0;
    for (ll i = 1; i < N - 1; ++i) {
        remain_water += min(right_max[i], left_max[i]) - b[i];
    }
    return remain_water;
}

int main() {
    cin >> N >> M;
    for (ll i = 0; i < N; ++i) {
        cin >> a[i];
    }
    ll left = 1, right = 2e9;
    ll ans = -1;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (f(mid) >= M) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << ans;
    return 0;
}