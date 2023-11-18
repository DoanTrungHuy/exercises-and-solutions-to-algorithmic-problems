#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lld = long double;

ll N, P;
const ll MN = 1e5 + 100;
ll lb[MN], rb[MN];

lld calc(ll i) {
    return 1.0*(rb[i] / P - (lb[i] - 1) / P) / (rb[i] - lb[i] + 1);
}

int main() {
    cin >> N >> P;
    for (ll i = 0; i < N; ++i) {
        cin >> lb[i] >> rb[i];
    }
    lld ans = 0;
    for (ll i = 0; i < N; ++i) {
        ll j = (i + 1) % N;
        lld px = calc(i);
        lld py = calc(j);
        lld px_or_py = px + py - px*py;
        ans += 2000*px_or_py;
    }
    cout << fixed << setprecision(6) << ans;
    return 0;
}