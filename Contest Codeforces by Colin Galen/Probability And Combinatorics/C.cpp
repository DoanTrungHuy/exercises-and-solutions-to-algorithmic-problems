#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N;
const ll MN = 2e5 + 10;
const ll MOD = 998244353;
ll a[MN];

ll exp(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    ll res = exp(a, b / 2);
    res = (res * res) % MOD;
    if (b & 1) {
        return (res * a) % MOD;
    }
    return res;
}

int main() {
    cin >> N;
    for (ll i = 0; i < N; ++i) {
        cin >> a[i];
    }
    map<ll, ll> last_pos;
    ll max_pos_end = 0;
    ll n_group = 0;
    for (ll i = 0; i < N; ++i) {
        last_pos[a[i]] = i;
    }
    for (ll i = 0; i < N; ++i) {
        max_pos_end = max(max_pos_end, last_pos[a[i]]);
        if (i == max_pos_end) {
            n_group++;
        }
    }
    cout << exp(2, n_group - 1);
    return 0;
}