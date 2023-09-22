#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m, k;

int main()
{
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    cin >> n >> m >> k;
    vector<string> grid;
    for (ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        grid.push_back(s);
    }
    vector<string> ans;
    for (ll i = 0; i < n; ++i) {
        string tmp;
        for (ll j = 0; j < m; ++j) {
            ll t = k;
            char c = grid[i][j];
            while (t--) {
                tmp += c;
            }
        }
        ans.push_back(tmp);
    }
    for (string t : ans) {
        ll x = k;
        while (x--) {
            cout << t << '\n';
        }
    }
    return 0;
}