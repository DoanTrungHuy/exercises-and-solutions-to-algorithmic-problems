#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MN = 100;

int main()
{
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    const ll MM = 3;
    ll c[MM], m[MM];
    for (ll i = 0; i < MM; ++i) {
        cin >> c[i] >> m[i];
    }
    for (ll i = 0; i < MN; ++i) {
        ll s = (i) % MM;
        ll e = (i + 1) % MM;
        ll remain = min(m[s], c[e] - m[e]);

        m[e] += remain;
        m[s] -= remain;
    }
    for (ll i = 0; i < MM; ++i) {
        cout << m[i] << '\n';
    }
    return 0;
}