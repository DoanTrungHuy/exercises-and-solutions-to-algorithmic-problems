#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MN = 1e6 + 1;
string s;
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
    cin >> s;
    int n = (int)s.size();
    unordered_map<char, int> um;
    for (char c : s) {
        um[c]++;
    }
    p[0] = 1;
    for (int i = 1; i < MN; ++i) {
        p[i] = (p[i - 1]*i) % MOD;
    }
    ll res = p[n];
    for (const auto &[v, c] : um) {
        res = (res*exp(p[c], MOD - 2)) % MOD;
    }
    cout << res;
    return 0;
}