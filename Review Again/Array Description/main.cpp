#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MAXN = 1e5 + 1, MAXM = 101;
int x[MAXN];
int memo[MAXN][MAXM];
const int MOD = 1e9 + 7;

int dp(int i, int val) {
    if (!(1 <= val and val <= m)) {
        return 0;
    }
    if (memo[i][val] != -1) {
        return memo[i][val];
    }
    int ans = 0;
    if (x[i] == val or x[i] == 0) {
        ans = (ans + dp(i + 1, val)) % MOD;
        ans = (ans + dp(i + 1, val - 1)) % MOD;
        ans = (ans + dp(i + 1, val + 1)) % MOD;
    }
    return memo[i][val] = ans;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    memset(memo, -1, sizeof(memo));

    if (x[n - 1] == 0) {
        for (int i = 1; i <= m; ++i) {
            memo[n - 1][i] = 1;
        }
    }
    else {
        for (int i = 1; i <= m; ++i) {
            memo[n - 1][i] = 0;
        }
        memo[n - 1][x[n - 1]] = 1;
    }


    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans = (ans + dp(0, i)) % MOD;
    }

    cout << ans;

    return 0;
}
