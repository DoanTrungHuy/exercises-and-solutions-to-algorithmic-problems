#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N;
const ll MN = 1e6;
bool lucky[MN + 1];

int main() {
    memset(lucky, false, sizeof(lucky));
    cin >> N;
    for (ll i = 1; i <= N; ++i) {
        ll X;
        cin >> X;
        cout << (X % 2 == 0 or X % 5 == 0 ? "YES" : "NO") << '\n';
    }
    return 0;
}