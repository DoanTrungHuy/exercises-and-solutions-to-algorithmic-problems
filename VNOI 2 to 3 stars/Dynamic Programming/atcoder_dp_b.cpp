#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, K;
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
    for (ll j = 1; j <= K; ++j) {
        if (i + j >= N) {
            continue;
        }
        ans = min(ans, abs(h[i] - h[i + j]) + dp(i + j));
    }
    return memo[i] = ans;
}

int main() {
    cin >> N >> K;
    for (ll i = 0; i < N; ++i) {
        cin >> h[i];
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(0);
    return 0;
}