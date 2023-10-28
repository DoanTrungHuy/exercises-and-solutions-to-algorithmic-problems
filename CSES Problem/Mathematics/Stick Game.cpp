#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, K;
const ll MK = 100;
ll p[MK];
const ll MN = 1e6 + 1;
ll memo[MN];

ll dp(ll i) {
    if (i == 0) {
        return false;
    }
    if (memo[i] != -1) {
        return memo[i];
    }
    ll ans = 0;
    for (ll j = 0; j < K; ++j) {
        if (i - p[j] < 0) {
            continue;
        }
        ans |= !dp(i - p[j]);
    }
    return memo[i] = ans;
}

int main() {
    cin >> N >> K;
    for (ll i = 0; i < K; ++i) {
        cin >> p[i];
    }
    memset(memo, -1, sizeof(memo));
    dp(N);
    for (ll i = 1; i <= N; ++i) {
        cout << (memo[i] == 1 ? 'W' : 'L');
    }
    return 0;
}