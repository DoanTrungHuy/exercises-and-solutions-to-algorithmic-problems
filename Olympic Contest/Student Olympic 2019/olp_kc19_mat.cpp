#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll K, N, I, J, S;

ll mul(ll a, ll b) {
    if (b == 0) {
        return 0;
    }
    if (b == 1) {
        return a;
    }
    ll res = mul(a, b / 2);
    if (b & 1) {
        return (res + res + a) % S;
    }
    return (res + res) % S;
}

int main() {
    cin >> K >> N >> I >> J >> S;
    vector<vector<vector<ll>>> v;
    for (ll i = 0; i < K; ++i) {
        vector<vector<ll>> m(N, vector<ll>(N));
        for (ll x = 0; x < N; ++x) {
            for (ll y = 0; y < N; ++y) {
                cin >> m[x][y];
                m[x][y] = (m[x][y] % S + S) % S;
            }
        }
        v.push_back(m);
    }
    vector<ll> a = v[0][I - 1];
    for (ll i = 1; i < K; ++i) {
        vector<ll> t(N);
        for (ll y = 0; y < N; ++y) {
            for (ll k = 0; k < N; ++k) {
                t[y] = (t[y] + mul(a[k], v[i][k][y])) % S;
            }
        }
        a = t;
    }
    cout << (a[J - 1] + S) % S;
    return 0;
}