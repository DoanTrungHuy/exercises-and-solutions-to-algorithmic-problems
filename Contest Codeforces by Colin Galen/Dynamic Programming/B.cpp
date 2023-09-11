#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;

int main() {
    cin >> n >> k;
    cin >> s;

    bool canType[26] = {false};
    
    for (int i = 0; i < k; ++i) {
        char c;
        cin >> c;
        canType[c - 'a'] = true;
    }

    int a[n];

    for (int i = 0; i < n; ++i) {
        a[i] = canType[s[i] - 'a'];
    }

    int f[n + 1];
    f[0] = 0;
    long long total = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            f[i + 1] = 0;
        }
        else {
            f[i + 1] = f[i] + 1;
        }
        total += 1LL*f[i + 1];
    }

    cout << total;
    return 0;
}