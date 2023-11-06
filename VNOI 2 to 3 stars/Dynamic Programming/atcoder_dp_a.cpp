#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N;
const ll MN = 1e5 + 10;
ll h[MN];
ll memo[MN];

ll dp(ll i) {
    if (i == N - 1) {
        return 0;
    }
    if (memo[i] != -1) {
        return memo[i];
    }
    ll ans = INT_MAX;
    if (i + 1 < N) {
        ans = min(ans, abs(h[i] - h[i + 1]) + dp(i + 1));
    }
    if (i + 2 < N) {
        ans = min(ans, abs(h[i] - h[i + 2]) + dp(i + 2));
    }
    return memo[i] = ans;
}

int main() {
    cin >> N;
    for (ll i = 0; i < N; ++i) {
        cin >> h[i];
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(0);
    return 0;
}