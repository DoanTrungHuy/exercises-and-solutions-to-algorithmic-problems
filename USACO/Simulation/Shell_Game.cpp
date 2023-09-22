#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n;

int main()
{
    cin >> n;
    const ll m = 3;
    ll shell[m];
    for (ll i = 0; i < m; ++i) {
        shell[i] = i;
    }
    ll cnt_guess[m];
    memset(cnt_guess, 0, sizeof(cnt_guess));
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll a, b, g;
        cin >> a >> b >> g;
        a--;
        b--;
        g--;
        swap(shell[a], shell[b]);
        cnt_guess[shell[g]]++;
        ans = max(ans, cnt_guess[shell[g]]);
    }
    cout << ans;
    return 0;
}