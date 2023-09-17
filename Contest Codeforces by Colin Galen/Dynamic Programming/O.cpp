#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, k;
const ll MN = 3e5;
ll a[MN];

int main() {
    cin >> n >> k;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll l = 0, r = 0;
    ll sum_zero = 0;
    ll max_len = 0, last_index_valid = 0;
    while (r < n) {
        if (a[r] == 0) {
            sum_zero++;
        }
        while (l <= r and sum_zero > k) {
            if (a[l] == 0) {
                sum_zero--;
            }
            l++;
        }
        if (r - l + 1 > max_len) {
            max_len = r - l + 1;
            last_index_valid = r;
        }
        r++;
    }
    cout << max_len << '\n';
    for (ll i = last_index_valid, j = k; i >= 0 and j > 0; --i) {
        if (a[i] == 0) {
            a[i] = 1;
            j--;
        }
    }
    for (ll i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
	return 0;
}