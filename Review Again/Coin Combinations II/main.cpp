#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N, X;
const ll MN = 1e6 + 100;
ll a[MN];
const ll MOD = 1e9 + 7;
// dp[i][s]: dp[i + 1][s + a[i]]

int main() {
    cin >> N >> X;
    for (ll i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a, a + N);
    ll dp[X + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j + a[i] <= X; ++j) {
            (dp[j + a[i]] += dp[j]) %= MOD;
        }
    }
    cout << dp[X];
    return 0;
}
