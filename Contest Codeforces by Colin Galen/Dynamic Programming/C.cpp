#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> p;
const int MN = 1e3 + 1;
int memo[MN][1 << 3];
const int INF = 1e9;

int dp(int i, int mask) {
    if (mask == ((1 << 3) - 1)) {
        return 0;
    }
    if (i >= n) {
        return (mask == ((1 << 3) - 1) ? 0 : INF);
    }
    if (memo[i][mask] != -1) {
        return memo[i][mask];
    }
    return memo[i][mask] = min({
        p[i].first + dp(i + 1, mask | p[i].second),
        dp(i + 1, mask)
    });
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int price;
        string vitamin;
        cin >> price >> vitamin;
        int mask = 0;
        for (char c : vitamin) {
            mask |= (1 << (c - 'A'));
        }
        p.push_back({price, mask});
    }

    memset(memo, -1, sizeof(memo));
    int ans = dp(0, 0);

    cout << (ans == INF ? -1 : ans);

    return 0;
}