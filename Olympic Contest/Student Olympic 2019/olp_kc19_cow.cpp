#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = INT_MAX;
    for (ll i = 0; i < n; ++i) {
        ll x, y, r;
        cin >> x >> y >> r;
        ll dist = ceil(sqrt((x - a)*(x - a) + (y - b)*(y - b))) - r;
        ans = min(ans, dist - 1);
    }
    cout << max(ans, 0LL);
    return 0;
}