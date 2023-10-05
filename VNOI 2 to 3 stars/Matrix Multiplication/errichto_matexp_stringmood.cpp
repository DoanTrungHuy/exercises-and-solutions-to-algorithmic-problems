#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;
const ll MOD = 1e9 + 7;
ll n;

struct Matrix {
    ll row, col;
    vector<vector<ll>> data;

    Matrix(ll row, ll col) {
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
        Matrix A = *this, C(A.row, B.col);
        for (ll i = 0; i < A.row; ++i) {
            for (ll j = 0; j < B.col; ++j) {
                for (ll k = 0; k < A.col; ++k) {
                    C.data[i][j] = (C.data[i][j] + (A.data[i][k] * B.data[k][j]) % MOD) % MOD;
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
    cin >> n;
    Matrix M(2, 2);
    M.data = {
        {20, 6},
        {7, 19}
    };
    Matrix base(2, 1);
    base.data = {
        {0},
        {1}
    };
    Matrix result = exp(M, n) * base;
    cout << result.data[1][0];
    return 0;
}