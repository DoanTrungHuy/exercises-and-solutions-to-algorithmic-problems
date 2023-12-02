#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N, X;
const ll MN = 1e3 + 100;
ll h[MN], s[MN];

// DP[i][total]: DP[i + 1][total], DP[i + 1][total - h[i]] + s[i]

int main() {
    cin >> N >> X;
    for (ll i = 0; i < N; ++i) {
        cin >> h[i];
    }
    for (ll i = 0; i < N; ++i) {
        cin >> s[i];
    }
    int dp[N + 1][X + 1];
    memset(dp, 0, sizeof(dp));
    for (ll i = 0; i < N; ++i) {
        for (ll j = X; j >= 0; --j) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j + h[i] > X) {
                continue;
            }
            dp[i + 1][j + h[i]] = max(dp[i + 1][j + h[i]], (int)(dp[i][j] + s[i]));
        }
    }
    cout << dp[N][X];
    return 0;
}
