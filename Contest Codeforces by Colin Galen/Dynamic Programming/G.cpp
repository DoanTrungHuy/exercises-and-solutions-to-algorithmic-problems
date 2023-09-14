#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll v1, v2, t, d;
ll memo[101][1001];
const ll INF = 1e18;

ll dp(ll i, ll p) {
    if (i == t) {
        return p == v2 ? 0 : -INF;
    }
    if (memo[i][p] != -1) {
        return memo[i][p];
    }
    ll &ans = memo[i][p];
    ans = -INF;
    for (ll j = -d; j <= d; ++j) {
        if (0 <= p + j and p + j < 1000) {
            ans = max(ans, p + j + dp(i + 1, p + j));
        }
    }
    return ans;
}

int main() {
    cin >> v1 >> v2;
    cin >> t >> d;
    memset(memo, -1, sizeof(memo));
    cout << v1 + dp(1, v1);
    return 0;
}