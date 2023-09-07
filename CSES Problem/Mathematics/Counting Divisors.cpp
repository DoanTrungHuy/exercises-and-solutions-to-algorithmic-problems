#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        int s = 0;
        for (int i = 1; i*i <= x; ++i) {
            if (x % i == 0) {
                s += (i*i == x ? 1 : 2);
            }
        }
        cout << s << '\n';
    }
    return 0;
}