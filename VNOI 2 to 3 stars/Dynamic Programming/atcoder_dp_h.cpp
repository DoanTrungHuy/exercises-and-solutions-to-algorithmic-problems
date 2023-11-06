#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll H, W;
const ll MHW = 1e3;
const ll MOD = 1e9 + 7;
char s[MHW][MHW];

int main() {
    ll H, W;
    cin >> H >> W;
    for (ll i = 0; i < H; ++i) {
        string t;
        cin >> t;
        for (ll j = 0; j < W; ++j) {
            s[i][j] = t[j];
        }
    }
    ll dp[H][W];
    memset(dp, 0, sizeof(dp));
    for (ll i = 0; i < H; ++i) {
        if (s[i][0] == '#') {
            break;
        }
        dp[i][0] = 1;
    }
    for (ll i = 0; i < W; ++i) {
        if (s[0][i] == '#') {
            break;
        }
        dp[0][i] = 1;
    }
    for (ll i = 1; i < H; ++i) {
        for (ll j = 1; j < W; ++j) {
            if (s[i][j] != '#') {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }
    cout << dp[H - 1][W - 1];
    return 0;
}