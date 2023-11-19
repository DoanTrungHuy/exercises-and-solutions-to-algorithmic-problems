#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N;

int main() {
    cin >> N;
    string s;
    ll cnt = 0;
    char c = 'a';
    for (ll i = 0; i < N; ++i) {
        s += c;
        cnt++;
        if (cnt == 2) {
            if (c == 'a') {
                c = 'b';
            }
            else {
                c = 'a';
            }
            cnt = 0;
        }
    }
    cout << s;
    return 0;
}