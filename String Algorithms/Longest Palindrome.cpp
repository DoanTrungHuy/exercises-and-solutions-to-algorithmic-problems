#include <bits/stdc++.h>

using namespace std;

string s, t;
int n;
const int MN = 1e6 + 1;
using ull = unsigned long long;
ull h[2][MN], p[MN];
const ull BASE = 31, MOD = 1e9 + 7;

ull get_hash(int t, int i, int j) {
    return (h[t][j] - h[t][i - 1]*p[j - i + 1] + MOD*MOD) % MOD;
}

int get_index(int m) {
    for (int l = 1; l <= n - m + 1; ++l) {
        int r = l + m - 1;
        if (get_hash(0, l, r) == get_hash(1, n - r + 1, n - l + 1)) {
            return l - 1;
        }
    }
    return -1;
}

int main() {
    memset(h, 0, sizeof(h));
    memset(p, 0, sizeof(p));

    cin >> s;
    n = s.size();
    t = s;
    reverse(t.begin(), t.end());

    p[0] = 1;

    for (int i = 1; i <= n; ++i) {
        h[0][i] = (h[0][i - 1]*BASE + s[i - 1] - 'a' + 1) % MOD;
        h[1][i] = (h[1][i - 1]*BASE + t[i - 1] - 'a' + 1) % MOD;
        p[i] = (p[i - 1]*BASE) % MOD;
    }

    int idx_best = 0;
    int len_best = 1;

    int left = 1;
    int right = n / 2;

    while (left <= right) {
        int mid = (left + right) / 2;

        int idx = get_index(2*mid);

        if (idx == -1) {
            right = mid - 1;
        }
        else {
            if (2*mid > len_best) {
                len_best = 2*mid;
                idx_best = idx;
            }
            left = mid + 1;
        }
    }

    left = 1;
    right = n / 2;

    while (left <= right) {
        int mid = (left + right) / 2;

        int idx = get_index(2*mid + 1);

        if (idx == -1) {
            right = mid - 1;
        }
        else {
            if (2*mid + 1 > len_best) {
                len_best = 2*mid + 1;
                idx_best = idx;
            }
            left = mid + 1;
        }
    }

    cout << s.substr(idx_best, len_best);

    return 0;
}