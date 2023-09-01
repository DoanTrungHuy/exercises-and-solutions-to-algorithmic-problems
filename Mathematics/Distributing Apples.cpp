#include <bits/stdc++.h>

using namespace std;

using ll = long long;
ll n, m;
const int MN = 2e6 + 10;
ll p[MN];
const ll MOD = 1e9 + 7;

ll exp(ll a, ll b) {
    if (b == 0LL) {
        return 1;
    }
    ll res = exp(a, b / 2);
    if (b & 1) {
        return (((res*res) % MOD)*a) % MOD;
    }
    return (res*res)%MOD;
}

int main() {
    cin >> n >> m;
    p[0] = 1;
    for (int i = 1; i < n + m; ++i) {
        p[i] = (p[i - 1]*i) % MOD;
    }
    cout << (((p[n + m - 1]*exp(p[m], MOD - 2)) % MOD) * exp(p[n - 1], MOD - 2)) % MOD;
    return 0;
}