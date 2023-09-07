#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

ll p(ll a, ll b, const ll M) {
    if (b == 0) {
        return 1LL;
    }
    ll res = p(a, b / 2, M);
    if (b % 2 == 0) {
        return (res * res) % M;
    }
    return (((res * res) % M) * a) % M;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << p(a, p(b, c, MOD - 1), MOD) << '\n'; 
    }
    return 0;
}