#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n;

int main()
{
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    cin >> n;
    vector<ll> idx(n);
    for (ll i = 0; i < n; ++i) {
        cin >> idx[i];
        idx[i]--;
    }
    ll id[n];
    for (ll i = 0; i < n; ++i) {
        cin >> id[i];
    } 
    vector<ll> tmp = idx;
    for (ll i = 1; i <= 2; ++i) {
        vector<ll> tmp2(n);
        for (ll j = 0; j < n; ++j) {
            tmp2[j] = tmp[idx[j]];
        }
        tmp = tmp2;
    }
    for (ll i = 0; i < n; ++i) {
        cout << id[tmp[i]] << '\n';
    }
    return 0;
}