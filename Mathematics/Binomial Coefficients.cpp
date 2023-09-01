#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int n;
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

const int MN = 1e6 + 1;
ll p[MN];

int main() {
    cin >> n;

    p[0] = 1;

    for (int i = 1; i < MN; ++i) {
        p[i] = (p[i - 1]*(ll)i) % MOD;
    }

    while (n--) {
        ll a, b;
        cin >> a >> b;
        cout << (((p[a] * exp(p[b], MOD - 2)) % MOD) * (exp(p[a - b], MOD - 2)))%MOD << '\n';
    }

    return 0;
}