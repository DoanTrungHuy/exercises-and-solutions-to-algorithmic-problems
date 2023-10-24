#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
ll N;
const ll MOD = 1e9 + 7;
 
struct Matrix {
    ll row, col;
    vector<vector<ll>> mat;
 
    Matrix(ll row, ll col) {
        this->row = row;
        this->col = col;
        mat.resize(row, vector<ll>(col));
    }
 
    static Matrix identity(ll n) {
        Matrix T(n, n);
        for (ll i = 0; i < n; ++i) {
            T.mat[i][i] = 1;
        }
        return T;
    }
 
    Matrix operator * (Matrix B) {
        Matrix A = *this;
        Matrix C(A.row, B.col);
        for (ll i = 0; i < A.row; ++i) {
            for (ll j = 0; j < B.col; ++j) {
                for (ll k = 0; k < A.col; ++k) {
                    C.mat[i][j] = (C.mat[i][j] + (A.mat[i][k]*B.mat[k][j]) % MOD) % MOD;
                }
            }
        }
        return C;
    }
};
 
Matrix exp(Matrix a, ll b) {
    if (b == 0) {
        return Matrix::identity(a.row);
    }
    Matrix res = exp(a, b / 2);
    res = res * res;
    if (b & 1) {
        return res * a;
    }
    return res;
}
 
int main() {
    cin >> N;
    if (N == 0) {
        cout << 0;
        return 0;
    }
    Matrix base(2, 2);
    base.mat = {
        {1, 1},
        {1, 0}
    };
    Matrix res = exp(base, N - 1);
    cout << res.mat[0][0];
    return 0;
}