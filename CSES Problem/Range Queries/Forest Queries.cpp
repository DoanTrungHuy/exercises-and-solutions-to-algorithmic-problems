#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, q;
    cin >> n >> q;
    string s[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int dp[n + 1][n + 1] = {};
    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        for (int j = 1; j <= n; ++j) {
            sum += s[i - 1][j - 1] == '*';
            dp[i][j] = dp[i - 1][j] + sum;
        }
    }
    while (q--) {
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}