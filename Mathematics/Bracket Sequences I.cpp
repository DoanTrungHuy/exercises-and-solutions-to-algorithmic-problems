#include <bits/stdc++.h>

using namespace std;

using ll = long long;
ll n;
const ll MOD = 1e9 + 7;

ll exp(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    ll res = exp(a, b / 2);
    res = (res * res) % MOD;
    if (b & 1) {
        return (res * a) % MOD;
    }
    return res;
}

const int MN = 1e6 + 1;
ll p[MN];

ll C(ll n, ll k) {
    ll res = p[n];
    res = (res * exp(p[n - k], MOD - 2)) % MOD;
    res = (res * exp(p[k], MOD - 2)) % MOD;
    return res;
}

int main() {
    cin >> n;
    if (n & 1) {
        cout << 0;
        return 0;
    }
    p[0] = 1LL;
    for (int i = 1; i < MN; ++i) {
        p[i] = (p[i - 1] * i) % MOD;
    }
    cout << (C(n, n / 2) - C(n, n / 2 + 1) + MOD) % MOD;
    return 0;
}