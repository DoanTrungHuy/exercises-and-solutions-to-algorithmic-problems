#include <bits/stdc++.h>

using namespace std;

const int MN = 61;
int n;
int memo[MN];

int dp(int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 0;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    return memo[n] = 2*dp(n - 2);
}

int main() {
    cin >> n;
    memset(memo, -1, sizeof(memo));
    cout << dp(n);
    return 0;
}