#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MN = 404;
ll a[MN];
ll N;
ll memo[MN][MN];
ll pref[MN];

ll dp(ll i, ll j) {
    if (i == j) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    ll ans = LLONG_MAX;
    for (ll k = i; k < j; ++k) {
        ans = min({
            ans, dp(i, k) + dp(k + 1, j) + pref[j + 1] - pref[i]
        });
    }
    return memo[i][j] = ans;
}

int main() {
    memset(pref, 0, sizeof(pref));
    cin >> N;
    for (ll i = 0; i < N; ++i) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(0, N - 1);
    return 0;
}