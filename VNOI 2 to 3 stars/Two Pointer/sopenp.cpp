#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, L, U;
ll a[1 << 20];

ll calc(ll x) {
    map<ll, ll> um;
    ll s = 0;
    for (ll i = 0, j = 0; i < N; ++i) {
        um[a[i]]++;
        while (um.size() > x) {
            if (--um[a[j]] == 0) {
                um.erase(a[j]);
            }
            j++;
        }
        s += i - j + 1;
    }
    return s;
}

int main() {
    cin >> N >> L >> U;
    for (ll i = 0; i < N; ++i) {
        cin >> a[i];
    }
    cout << calc(U) - calc(L - 1);
    return 0;
}