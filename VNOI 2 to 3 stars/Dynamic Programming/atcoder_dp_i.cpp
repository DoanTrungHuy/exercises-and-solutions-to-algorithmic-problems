#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N;
const ll MN = 3e3 + 10;
double p[MN];
double memo[MN][MN];

double dp(ll i, ll j) {
    if (i == N) {
        if (j > N - j) {
            return 1.0;
        }
        return 0.0;
    }
    if (memo[i][j] != -1.0) {
        return memo[i][j];
    }
    return memo[i][j] = p[i]*dp(i + 1, j + 1) + (1 - p[i])*dp(i + 1, j);
}

int main() {
    cin >> N;
    for (ll i = 0; i < N; ++i) {
        cin >> p[i];
    }
    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j < N; ++j) {
            memo[i][j] = -1.0;
        }
    }
    cout << fixed << setprecision(9) << dp(0, 0);
    return 0;
}