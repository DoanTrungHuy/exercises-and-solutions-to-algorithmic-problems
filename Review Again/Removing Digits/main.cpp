#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N;
const ll MN = 1e6 + 100;
ll a[MN];
ll memo[MN];
const ll MOD = 1e9 + 7;

ll dp(ll s) {
    if (s == 0) {
        return 0;
    }
    if (s < 0) {
        return INT_MAX;
    }
    if (memo[s] != -1) {
        return memo[s];
    }
    ll ans = INT_MAX;
    for (char c : to_string(s)) {
        if (c == '0') {
            continue;
        }
        ans = min(ans, 1 + dp(s - (c - '0')));
    }
    return memo[s] = ans;
}

int main() {
    cin >> N;
    memset(memo, -1, sizeof(memo));
    cout << dp(N);
    return 0;
}
