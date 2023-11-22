#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N;
const ll MN = 1e5 + 100;
ll a[MN];

int main() {
    ll L, R;
    cin >> L >> R;
    ll A = L ^ R;
    if (!A) {
        cout << 0;
        return 0;
    }
    ll cnt = 64 - (ll)__builtin_clzll(A);
    cout << (1LL << cnt) - 1;
    return 0;
}