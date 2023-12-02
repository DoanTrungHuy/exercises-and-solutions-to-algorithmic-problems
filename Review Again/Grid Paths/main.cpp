#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N;
const ll MN = 1e5 + 100;
ll a[MN];
const ll MOD = 1e9 + 7;

int main() {
    cin >> N;
    string s[N];
    for (ll i = 0; i < N; ++i) {
        cin >> s[i];
    }
    ll dp[N + 1][N + 1];
    memset(dp, 0, sizeof(dp));
    for (ll i = 0; i < N; ++i) {
        if (s[i][0] == '*') {
            break;
        }
        dp[i][0] = 1;
    }
    for (ll i = 0; i < N; ++i) {
        if (s[0][i] == '*') {
            break;
        }
        dp[0][i] = 1;
    }
    for (ll i = 1; i < N; ++i) {
        for (ll j = 1; j < N; ++j) {
            if (s[i][j] == '*') {
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[N - 1][N - 1];
    return 0;
}
