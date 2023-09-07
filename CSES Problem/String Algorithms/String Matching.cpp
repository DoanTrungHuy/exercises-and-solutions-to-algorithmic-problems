#include <bits/stdc++.h>

using namespace std;

string s, t;
using ull = unsigned long long;
const int MN = 1e6 + 1;
ull h[MN], p[MN];
ull base = 17113;
const ull MOD = 1e9 + 7;

int main() {
    cin >> s >> t;
    int n = s.size();
    int m = t.size();

    h[0] = 0;
    p[0] = 1;

    for (int i = 1; i <= n; ++i) {
        h[i] = (h[i - 1]*base + s[i - 1] - 'a' + 1) % MOD;
        p[i] = (p[i - 1]*base) % MOD;
    }

    ull ht = 0;

    for (int i = 1; i <= m; ++i) {
        ht = (ht*base + t[i - 1] - 'a' + 1) % MOD;
    }

    int cnt = 0; 

    auto get_hash = [&](int i, int j) -> ull {
        return (h[j] - h[i - 1]*p[j - i + 1] + MOD*MOD) % MOD;
    };

    for (int i = 1; i <= n - m + 1; ++i) {
        if (get_hash(i, i + m - 1) == ht) {
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}