#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

ll p(ll a, ll b) {
    if (b == 0) {
        return 1LL;
    }
    ll res = p(a, b / 2);
    if (b % 2 == 0) {
        return (res * res) % MOD;
    }
    return (((res * res) % MOD) * a) % MOD;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        ll a, b;
        cin >> a >> b;
        cout << p(a, b) << '\n'; 
    }
    return 0;
}