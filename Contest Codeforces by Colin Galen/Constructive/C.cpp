#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string s;

int main() {
    cin >> s;
    ll cnt_r[2] = {0, 0};
    for (char c : s) {
        if (c == '1') {
            cout << 1 << ' ' << (cnt_r[0] == 0 ? 1 : 3) << '\n';
            cnt_r[0] = (cnt_r[0] + 1) % 2;
        }
        else {
            cout << 2 << ' ' << cnt_r[1] + 1 << '\n';
            cnt_r[1] = (cnt_r[1] + 1) % 4;
        }
    }
    return 0;
}