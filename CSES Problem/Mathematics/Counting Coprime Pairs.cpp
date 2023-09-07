#include <bits/stdc++.h>

using namespace std;

using ll = long long;
ll n;
const int MN = 1e6 + 1;
ll x[MN];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<vector<ll>> sieve(MN);

    for (int i = 2; i < MN; ++i) {
        if (sieve[i].size() == 0) {
            sieve[i].push_back(i);
            for (int j = 2*i; j < MN; j += i) {
                sieve[j].push_back(i);
            }
        }
    }

    vector<ll> cnt_value_prime(MN);

    for (int i = 0; i < n; ++i) {
        const int m = sieve[x[i]].size();
        for (int mask = 1; mask < (1 << m); ++mask) {
            int combination = 1;
            for (int j = 0; j < m; ++j) {
                if (mask & (1 << j)) {
                    combination *= sieve[x[i]][j];
                }
            }
            cnt_value_prime[combination]++;
        }
    }

    ll total = (ll)n*(n - 1) / 2;
    ll other_gcd_one = 0LL;

    for (int i = 2; i < MN; ++i) {
        ll v = cnt_value_prime[i];
        if (sieve[i].size() & 1) {
            other_gcd_one += v*(v - 1) / 2;
        }
        else {
            other_gcd_one -= v*(v - 1) / 2;
        }
    }

    cout << (total - other_gcd_one);

    return 0;
}