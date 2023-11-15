#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

ll N;

ll exp(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    ll res = exp(a, b / 2);
    res = res * res;
    if (b & 1) {
        return res * a;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for (ll i = 0; i < N; ++i) {
        ll Ax, Bx, Ay, By;
        cin >> Ax;
        ll X = 0;
        if (Ax > 0) {
            cin >> Bx;
            X = Ax * exp(10, Bx);
        }
        else {
            string s;
            cin >> s;
        }
        cin >> Ay;
        ll Y = 0;
        if (Ay > 0) {
            cin >> By;
            Y = Ay * exp(10, By);
        }
        else
        if (X == Y) {
            cout << "X = Y" << '\n';
        }
        else if (X > Y) {
            cout << "X > Y" << '\n';
        }
        else {
            cout << "X < Y" << '\n';
        }
    }
    return 0;
}