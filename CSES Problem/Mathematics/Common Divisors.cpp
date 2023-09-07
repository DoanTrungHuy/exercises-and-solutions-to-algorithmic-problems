#include <bits/stdc++.h>

using namespace std;

const int MN = 1e6 + 1;
int cnt[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int m = 0;

    while (n--) {
        int x;
        cin >> x;
        const int sqrt_x = sqrt(x);
        for (int i = 1; i <= sqrt_x; ++i) {
            if (x % i == 0) {
                cnt[i]++;
                if (i*i != x) {
                    cnt[x / i]++;
                }
            }
        }
        m = max(m, x);
    }

    for (int i = m; i >= 1; --i) {
        if (cnt[i] >= 2) {
            cout << i;
            break;
        }
    }

    return 0;
}