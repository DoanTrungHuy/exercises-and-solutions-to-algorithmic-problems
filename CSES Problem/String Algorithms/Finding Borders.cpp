#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
const ull MOD = 1e9 + 7;
ull base = 17117;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    ull pref = 0;
    ull suff = 0;
    ull p = 1;

    vector<int> border_duplicate;

    for (int i = 1; i <= n - 1; ++i) {
        pref = (pref*base + s[i - 1] - 'a' + 1) % MOD;
        suff = ((s[n - i] - 'a' + 1)*p + suff) % MOD;
        p = (p*base) % MOD;

        if (pref == suff) {
            border_duplicate.push_back(i);
        }
    }

    for (int len : border_duplicate) {
        cout << len << ' ';
    }

    return 0;
}