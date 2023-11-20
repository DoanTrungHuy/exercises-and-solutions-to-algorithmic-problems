#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N;
const ll MN = 1e5 + 100;
ll a[MN];

int main() {
    cin >> N;
    unordered_map<ll, ll> cnt;
    ll ans = 0;
    for (ll i = 0; i < N; ++i) {
        string s;
        cin >> s;
        ll mask = 0;
        for (char c : s) {
            mask ^= (1LL << (c - 'a'));
        }
        ans += cnt[mask];
        for (ll i = 0; i < 26; ++i) {
            ans += cnt[mask ^ (1LL << i)];
        }
        cnt[mask]++;
    }
    cout << ans;
    return 0;
}