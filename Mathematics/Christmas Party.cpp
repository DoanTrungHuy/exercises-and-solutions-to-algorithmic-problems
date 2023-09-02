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

int main() {
    cin >> n;
    p[0] = 1;
    for (int i = 1; i < MN; ++i) {
        p[i] = (p[i - 1]*i) % MOD;
    }
    ll case_bad = 0LL;
    for (int i = 1; i <= n; ++i) {
        case_bad = (case_bad + p[n]*exp(p[i], MOD - 2)*exp(-1, i + 1) % MOD) % MOD;
    } 
    cout << (p[n] - case_bad + MOD) % MOD;
    return 0;
}