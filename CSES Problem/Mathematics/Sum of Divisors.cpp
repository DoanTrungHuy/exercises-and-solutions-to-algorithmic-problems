#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

ll p(ll a, ll b) {
    if (b == 0) {
        return 1LL;
    }
    ll res = p(a, b / 2);
    if (b & 1) {
        return (((res * res) % MOD) * a) % MOD;
    }
    else {
        return (res * res) % MOD;
    }
}

ll sum(ll n) {
    return (((n % MOD) * ((n + 1) % MOD)) % MOD * p(2, MOD - 2)) % MOD;
}

int main() {
    ll n;
    cin >> n;
    ll total = 0LL;
    ll l = 1;
    while (l <= n) {
        ll k = n / l;
        ll r = n / k;
        k %= MOD;
        total = (total + ((sum(r) - sum(l - 1))*k) % MOD) % MOD;
        l = r + 1;
    }
    cout << (total + MOD) % MOD;
    return 0;
}