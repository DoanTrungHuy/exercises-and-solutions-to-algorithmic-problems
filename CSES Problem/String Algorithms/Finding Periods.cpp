#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
ull base = 17117;
const ull MOD = 1e9 + 7;
const int MAXN = 1e6 + 1;
ull h[MAXN], p[MAXN];

int main() {
    string s;
    cin >> s;
    int n = s.size();

    h[0] = 0;
    p[0] = 1;

    for (int i = 1; i <= n; ++i) {
        h[i] = (h[i - 1]*base + s[i - 1] - 'a' + 1) % MOD;
        p[i] = (p[i - 1]*base) % MOD;
    }

    auto get_hash = [&](int i, int j) -> ull {
        return (h[j] - h[i - 1]*p[j - i + 1] + MOD*MOD) % MOD;
    };

    for (int len = 1; len <= n; ++len) {
        bool flag = true;
        for (int i = len; i + len <= n; i += len) {
            flag &= get_hash(1, len) == get_hash(i + 1, i + len);
        }
        int d = n % len;
        flag &= get_hash(1, d) == get_hash(n - (d - 1), n);
        if (flag) {
            cout << len << ' ';
        }
    }

    return 0;
}