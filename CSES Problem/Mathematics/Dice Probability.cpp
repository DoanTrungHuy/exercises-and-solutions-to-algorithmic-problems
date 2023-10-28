#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MN = 102;
double memo[MN][6*MN];
ll N, A, B;

double dp(ll i, ll k) {
    if (i == N) {
        return !k;
    }
    if (k > 6 * N or k < 0) {
        return 0;
    }
    if (memo[i][k] + 1.0 <= 1e9) {
        return memo[i][k];
    }
    double ways = 0;
    for (ll j = 1; j <= 6; ++j) {
        if (k - j >= 0) {
            ways += dp(i + 1, k - j);
        }
    }
    return memo[i][k] = ways / 6.0;
}

int main() {
    memset(memo, -1, sizeof(memo));
    cin >> N >> A >> B;
    double res = 0;
    for (ll k = A; k <= B; ++k) {
        res += dp(0, k);
    }
    cout << fixed << setprecision(6) << res;
    return 0;
}