#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string s, t;
const ll MN = 3002;
ll memo[MN][MN];
ll color[MN][MN];

#define EQ 1
#define PI 2
#define PJ 3

ll dp(ll i, ll j) {
    if (i == (ll)s.size()) {
        return 0;
    }
    if (j == (ll)t.size()) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    if (s[i] == t[j]) {
        color[i][j] = EQ;
        return memo[i][j] = 1 + dp(i + 1, j + 1);
    }
    ll ans = 0;
    {
        ll tmp = dp(i + 1, j);
        if (tmp > ans) {
            ans = tmp;
            color[i][j] = PI;
        }
    }
    {
        ll tmp = dp(i, j + 1);
        if (tmp > ans) {
            ans = tmp;
            color[i][j] = PJ;
        }
    }
    return memo[i][j] = ans;
}

int main() {
    cin >> s >> t;
    const ll n = s.size(), m = t.size();
    memset(memo, -1, sizeof(memo));
    dp(0, 0);
    ll i = 0, j = 0;
    string ans = "";
    while (i < n or j < m) {
        if (color[i][j] == EQ) {
            ans += s[i];
            i++;
            j++;
        }
        else if (color[i][j] == PI) {
            i++;
        }
        else if (color[i][j] == PJ) {
            j++;
        }
        else {
            i++;
            j++;
        }
    }
    cout << ans;
    return 0;
}