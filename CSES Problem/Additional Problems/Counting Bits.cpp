#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N;
const ll MN = 1e5 + 100;
ll a[MN];
string s;
ll memo[60][2][60];

ll dp(ll i, ll tight, ll cnt) {
    if (i == (ll)s.size()) {
        return cnt;
    }
    if (memo[i][tight][cnt] != -1LL) {
        return memo[i][tight][cnt];
    }
    ll limit_num = tight ? s[i] - '0' : 1;
    ll ans = 0;
    for (ll j = 0; j <= limit_num; ++j) {
        ans += dp(i + 1, tight and j == limit_num, cnt + (j == 1));
    }
    return memo[i][tight][cnt] = ans;
}

int main() {
    cin >> N;
    while (N > 0) {
        s += (N % 2 + '0');
        N /= 2;
    }
    reverse(s.begin(), s.end());
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 1, 0);
    return 0;
}