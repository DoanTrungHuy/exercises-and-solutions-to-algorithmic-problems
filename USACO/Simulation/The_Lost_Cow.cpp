#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll x, y;

int main()
{
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    cin >> x >> y;
    ll step = 1;
    ll answ = 0;
    while (true) {
        ll new_x = x + step;
        answ += abs(x - new_x);
        if (min(new_x, x) <= y and y <= max(new_x, x)) {
            answ -= abs(y - new_x);
            break;
        }
        else {
            answ += abs(x - new_x);
        }
        step *= -2;
    }
    cout << answ;
    return 0;
}