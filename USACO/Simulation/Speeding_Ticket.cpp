#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m;

int main()
{
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    cin >> n >> m;

    const ll MN = 101;

    ll limit_speed[MN] = {};
    ll curr_speed = 0;

    for (ll i = 0; i < n; ++i) {
        ll miles, speed;
        cin >> miles >> speed;
        while (miles--) {
            limit_speed[curr_speed++] = speed;
        }
    }

    ll travel_speed[MN] = {};
    curr_speed = 0;

    for (ll i = 0; i < m; ++i) {
        ll miles, speed;
        cin >> miles >> speed;
        while (miles--) {
            travel_speed[curr_speed++] = speed;
        }
    }

    ll ans = 0;

    for (ll i = 0; i < MN; ++i) {
        ll amount_over_speed = travel_speed[i] - limit_speed[i];
        ans = max(ans, amount_over_speed);
    }
    
    cout << ans;
    return 0;
}