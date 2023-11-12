#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    ll a[N];
    ll odd = 0, even = 0;
    for (ll i = 0; i < N; ++i) {
        cin >> a[i];
        if (a[i] & 1) {
            odd++;
        }
        else {
            even++;
        }
    }
    cout << odd*(odd - 1) / 2 + even*(even - 1) / 2;
    return 0;
}