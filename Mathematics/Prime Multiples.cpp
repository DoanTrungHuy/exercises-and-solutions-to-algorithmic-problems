#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;

    ll a[k];

    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }

    ll set_num_div[k + 1] = {};

    for (int mask = 1; mask < (1 << k); ++mask) {
        int cnt = 0;
        ll cur_num = n;
        for (int i = 0; i < k; ++i) {
            if ((mask >> i) & 1) {
                cnt++;
                cur_num /= a[i];
            }
        }
        set_num_div[cnt] += cur_num;
    }

    ll ans = 0LL;

    for (int i = 1; i <= k; ++i) {
        if (i & 1) {
            ans += set_num_div[i];
        }
        else {
            ans -= set_num_div[i];
        }
    }

    cout << ans;

    return 0;
}