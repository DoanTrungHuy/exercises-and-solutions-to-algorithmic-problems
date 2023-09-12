#include <bits/stdc++.h>

using namespace std;

int n, k;
const int MN = 1e5 + 1;
int a[MN], t[MN];

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    int p[2][n + 1];
    p[0][0] = 0;
    p[1][0] = 0;

    for (int i = 1; i <= n; ++i) {
        p[0][i] = p[0][i - 1] + a[i]*t[i];
        p[1][i] = p[1][i - 1] + a[i];
    }

    int ans = p[0][n];

    for (int i = 1; i <= n; ++i) {
        if (t[i] == 0) {
            int range[3];
            range[0] = p[0][i - 1];
            range[1] = p[1][min(n, i + k - 1)] - p[1][i - 1];
            range[2] = p[0][n] - p[0][min(n, i + k - 1)];
            ans = max(ans, range[0] + range[1] + range[2]);
        }
    }

    cout << ans;

    return 0;
}