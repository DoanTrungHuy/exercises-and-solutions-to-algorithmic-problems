#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N;
const ll MN = 3e3 + 10;
ll a[MN];
ll memo[2][MN][MN];

ll dp(ll state, ll i, ll j) {
    if (j < i) {
        return 0;
    }
    if (memo[state][i][j] != -1) {
        return memo[state][i][j];
    }
    if (!state) {
        return memo[state][i][j] = max(dp(!state, i + 1, j) + a[i], dp(!state, i, j - 1) + a[j]);
    }
    return memo[state][i][j] = min(dp(!state, i + 1, j) - a[i], dp(!state, i, j - 1) - a[j]);
}

int main() {
    cin >> N;
    for (ll i = 0; i < N; ++i) {
        cin >> a[i];
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0, N - 1);
    return 0;
}