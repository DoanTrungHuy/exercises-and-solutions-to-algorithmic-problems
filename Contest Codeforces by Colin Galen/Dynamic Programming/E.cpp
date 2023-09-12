#include <bits/stdc++.h>

using namespace std;

using ll = long long;
ll n, k, p;
const int MN = 2e3 + 1;
ll a[MN], b[MN];
ll memo[MN][MN];
const ll INF = 1e17;

ll dp(int i, int j) {
    if (j == k) {
        return (i == n ? 0 : INF);
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    return memo[i][j] = min({
        max(abs(a[i] - b[j]) + abs(b[j] - p), dp(i + 1, j + 1)),
        dp(i, j + 1)
    });
}

int main() {
    cin >> n >> k >> p;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    for (int i = 0; i < k; ++i) {
        cin >> b[i];
    }
    sort(b, b + k);

    memset(memo, -1, sizeof(memo));

    cout << dp(0, 0);

    return 0;
}