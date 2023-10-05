#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;
const ll MOD = 1e9 + 7;
ll n, m, k;

struct Matrix {
    ll row, col;
    vector<vector<ll>> data;
    
    Matrix(ll row = 0, ll col = 0) {
        this->row = row;
        this->col = col;
        data.resize(row, vector<ll>(col, 0));
    }
    
    static Matrix identity(ll n) {
        Matrix M(n, n);
        for (ll i = 0; i < n; ++i) {
            M.data[i][i] = 1;
        }
        return M;
    }
    
    Matrix operator * (Matrix B) {
        Matrix A = *this;
        Matrix C(A.row, B.col);
        for (ll i = 0; i < A.row; ++i) {
            for (ll j = 0; j < B.col; ++j) {
                for (ll k = 0; k < A.col; ++k) {
                    C.data[i][j] = (C.data[i][j] + (A.data[i][k]%MOD*B.data[k][j]%MOD) % MOD) % MOD;
                }
            }
        }
        return C;
    }
};

Matrix exp(Matrix A, ll b) {
    if (b == 0) {
        return Matrix::identity(A.row);
    }
    Matrix res = exp(A, b / 2);
    res = res * res;
    if (b & 1) {
        res = res * A;
    }
    return res;
}

int main() {
    cin >> n >> m >> k;
    Matrix M(n, n);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        M.data[u][v] = 1;
    }
    Matrix base(n, 1);
    for (ll i = 0; i < n; ++i) {
        base.data[i][0] = 1;
    }
    Matrix result = exp(M, k) * base;
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans = (ans + result.data[i][0]) % MOD;
    }
    cout << ans;
    return 0;
}