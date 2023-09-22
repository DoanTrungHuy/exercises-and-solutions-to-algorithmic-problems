#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m, k;
const ll MN = 1e5 + 5;
ll a[MN], M[MN][3];

int main()
{
    cin >> n >> m >> k;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (ll i = 1; i <= m; ++i) {
        for (ll j = 0; j < 3; ++j) {
            cin >> M[i][j];
        }
    }
    ll freq_opr[MN];
    memset(freq_opr, 0, sizeof(freq_opr));
    for (ll i = 1; i <= k; ++i) {
        ll x, y;
        cin >> x >> y;
        freq_opr[x]++;
        freq_opr[y + 1]--;
    }
    ll diff[MN] = {};
    memset(diff, 0, sizeof(diff));
    for (ll i = 1; i <= m; ++i) {
        freq_opr[i] += freq_opr[i - 1];
        diff[M[i][0]] += freq_opr[i]*M[i][2];
        diff[M[i][1] + 1] -= freq_opr[i]*M[i][2];
    }
    for (ll i = 1; i <= n; ++i) {
        diff[i] += diff[i - 1];
        cout << a[i] + diff[i] << ' ';
    }
    return 0;
}