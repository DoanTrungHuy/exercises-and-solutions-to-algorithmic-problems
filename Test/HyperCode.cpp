#include <bits/stdc++.h>

using namespace std;

int n;
const int MN = 501;
string x[MN];

bool two_pointer(string &s, string &t) {
    int j = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == t[j]) {
            j++;
        }
    }
    return j == (int)t.size();
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (x[j].size() > x[i].size()) {
                continue;
            }
            if (two_pointer(x[i], x[j])) {
                cout << 0 << '\n' << i;
                return 0;
            }
        }
    }
    cout << 1;
    return 0;
}