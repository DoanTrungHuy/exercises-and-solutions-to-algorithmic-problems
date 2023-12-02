#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N, X;
const ll MN = 1e6 + 100;
ll a[MN];

// DP[i][j]: DP[i][j + a[i]] + 1, DP[i + 1][j]

int main() {
    cin >> N >> X;
    for (ll i = 0; i < N; ++i) {
        cin >> a[i];
    }
    int dp[N + 10][X + 10];
    for (ll i = 0; i <= N; ++i) {
        for (ll j = 0; j <= X; ++j) {
            dp[i][j] = 1e7;
        }
    }
    dp[0][0] = 0;
    for (ll j = 0; j <= X; ++j) {
        for (ll i = 0; i < N; ++i) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if (j + a[i] > X) {
                continue;
            }
            dp[i][j + a[i]] = min(dp[i][j + a[i]], dp[i][j] + 1);
        }
    }
    cout << (dp[N - 1][X] == 1e7 ? -1 : dp[N - 1][X]);
    return 0;
}
