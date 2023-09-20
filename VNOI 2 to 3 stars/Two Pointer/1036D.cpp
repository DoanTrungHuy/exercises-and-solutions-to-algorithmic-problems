#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m;
const ll MN = 3e5;
ll a[MN], b[MN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> b[i];
    }
    ll cnt = 0;
    ll sum[2] = {a[0], b[0]};
    ll i = 0, j = 0;
    while (i < n and j < m) {
        if (sum[0] == sum[1]) {
            cnt++;
            i++;
            j++;
            sum[0] += a[i];
            sum[1] += b[j];
        }
        else if (sum[0] > sum[1]) {
            j++;
            sum[1] += b[j];
        }
        else {
            i++;
            sum[0] += a[i];
        }
    }
    if (i != n or j != m) {
        cout << -1;
    }
    else {
        cout << cnt;
    }
    return 0;
}