#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, x;
const ll MN = 1e6;
ll a[MN];

int main()
{
    cin >> n >> x;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll i = 0, j = n - 1;
    while (i < j) {
        if (a[i] + a[j] == x) {
            cout << i + 1 << ' ' << j + 1;
            return 0;
        }
        else if (a[i] + a[j] > x) {
            j--;
        }
        else {
            i++;
        }
    }
    cout << "No solution";
    return 0;
}