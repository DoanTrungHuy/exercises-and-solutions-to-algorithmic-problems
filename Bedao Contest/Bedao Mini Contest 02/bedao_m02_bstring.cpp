#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(false); cin.tie(0);

int main() {
    fastIO
    ll N;
    cin >> N;
    string s;
    cin >> s;
    ll cnt[2] = {0, 0};
    for (ll i = 1; i <= N; ++i) {
        cnt[0] += (s[i - 1] == '0');
        cnt[1] += (s[i - 1] == '1');
    }
    ll ans = INT_MAX;
    {
        ll del = 0;
        for (ll i = 1; i <= cnt[0]; ++i) {
            del += (s[i - 1] == '1');
        }
        ans = min(ans, del);
    }
    {
        ll del = 0;
        for (ll i = 1; i <= cnt[1]; ++i) {
            del += (s[i - 1] == '0');
        }
        ans = min(ans, del);
    }
    cout << ans;
    return 0;
}