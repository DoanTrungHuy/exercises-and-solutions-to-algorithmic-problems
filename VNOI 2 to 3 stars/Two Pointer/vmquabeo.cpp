#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, L, D;
const ll MN = 1e6;
ll H[MN];

int main() {
    cin >> N >> L >> D;
    L += 1;
    for (ll i = 0; i < N; ++i) {
        cin >> H[i];
    }
    ll s = 0;
    multiset<ll> ms;
    for (ll i = 0, j = 0; i < N; ++i) {
        ms.insert(H[i]);
        while (ms.size() and *ms.rbegin() - *ms.begin() > D) {
            ms.erase(ms.find(H[j]));
            j++;
        }
        if (i - j + 1 >= L) {
            s += (i - j + 1) - (L - 1);
        }
    }
    cout << s;
    return 0;
}