#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, x;
const ll MN = 1e6;
ll a[MN];

int main()
{
    cin >> n >> x;
    map<ll, ll> mm;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        mm[a[i]]++;
    }
    vector<ll> v;
    for (const auto [val, _] : mm) {
        v.push_back(val);
    }
    ll i = 0, j = v.size() - 1;
    ll cnt = 0;
    while (i <= j) {
        if (v[i] + v[j] == x) {
            if (v[i] != v[j]) {
                cnt = cnt + mm[v[i]]*mm[v[j]];
            }
            else {
                cnt = cnt + mm[v[i]]*(mm[v[i]] - 1) / 2;
            }
            i++;
            j--;
        }
        else if (v[i] + v[j] > x) {
            j--;
        }
        else {
            i++;
        }
    }
    cout << cnt;
    return 0;
}