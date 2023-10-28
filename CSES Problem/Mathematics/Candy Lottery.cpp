#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, k;

int main() {
    cin >> n >> k;
    double res = 0;
    for (ll i = 1; i <= k; ++i) {
        res += 1.0*i*(pow((i*1.0 / k), n) - pow(((i*1.0 - 1) / k), n));
    }
    cout << fixed << setprecision(6) << res;
    return 0;
}