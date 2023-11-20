#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll K, N, I, J, S;
vector<vector<vector<ll>>> mats;

ll mul(ll a, ll b) {
    if (b == 0) {
        return 0;
    }
    ll res = mul(a, b / 2);
    res = (res + res) % S;
    if (b & 1) {
        return (res + a) % S;
    }
    return res;
}

int main() {
    cin >> K >> N >> I >> J >> S;
    for (ll i = 0; i < K; ++i) {
        vector<vector<ll>> mat(N, vector<ll>(N));
        for (ll x = 0; x < N; ++x) {
            for (ll y = 0; y < N; ++y) {
                cin >> mat[x][y];
                mat[x][y] = (mat[x][y] + S) % S;
            }
        }
        mats.push_back(mat);
    }
    vector<ll> fmat = mats[0][I - 1];
    for (ll i = 1; i < K; ++i) {
        vector<ll> res(N);
        for (ll y = 0; y < N; ++y) {
            for (ll k = 0; k < N; ++k) {
                res[y] = (res[y] + mul(fmat[k], mats[i][k][y])) % S;
            }
        }
        fmat = res;
    }
    cout << (fmat[J - 1] + S) % S;
    return 0;
}