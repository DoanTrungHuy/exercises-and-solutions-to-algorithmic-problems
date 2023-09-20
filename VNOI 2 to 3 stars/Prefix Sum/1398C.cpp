#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll t;

int main()
{
    cin >> t;
    while (t--) {
        ll n;
        string s;
        cin >> n >> s;
        ll p[n + 1];
        p[0] = 0;
        for (ll i = 0; i < n; ++i) {
            p[i + 1] = p[i] + s[i] - '0';
        } 
        unordered_map<ll, ll> um;
        ll total = 0;
        for (ll i = 0; i <= n; ++i) {
            total += um[p[i] - i];
            um[p[i] - i]++;
        }
        cout << total << '\n';
    }
    return 0;
}