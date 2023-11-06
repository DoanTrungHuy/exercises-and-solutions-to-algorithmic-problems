#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, K;
const ll MN = 101, MK = 1e5 + 10;
ll a[MN];
ll memo[MK];

ll dp(ll k) {
    if (k == 0) {
        return 0;
    }
    if (memo[k] != -1) {
        return memo[k];
    }
    ll ans = 0;
    for (ll i = 0; i < N; ++i) {
        if (k - a[i] >= 0) {
            ans |= (dp(k - a[i]) ^ 1);
        }
    }
    return memo[k] = ans;
}

int main() {
    cin >> N >> K;
    for (ll i = 0; i < N; ++i) {
        cin >> a[i];
    }
    memset(memo, -1, sizeof(memo));
    if (dp(K)) {
        cout << "First";
    }
    else {
        cout << "Second";
    }
    return 0;
}