#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll MN = 64;
const ll MOD = 1LL << 32;
ll k;

struct Matrix {
    ll row, col;
    vector<vector<unsigned ll>> data;
    
    Matrix(ll row = 0, ll col = 0) {
        this->row = row;
        this->col = col;
        data.resize(row, vector<unsigned ll>(col, 0));
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
                    C.data[i][j] = (C.data[i][j] + ((A.data[i][k]%MOD)*(B.data[k][j]%MOD)) % MOD) % MOD;
                }
            }
        }
        return C;
    }
};

Matrix exp(Matrix A, ll b) {
    if (b == 0) {
        return Matrix::identity(A.col);
    }
    Matrix res = exp(A, b / 2);
    res = res * res;
    if (b & 1) {
        res = res * A;
    }
    return res;
}

bool is_valid(ll r, ll c) {
    return 0 <= r and r < 8 and 0 <= c and c < 8;
}

int main() {
    cin >> k;
    Matrix M(MN + 1, MN + 1);
    for (ll i = 0; i < 8; ++i) {
        for (ll j = 0; j < 8; ++j) {
            for (ll dr : {-2, -1, 1, 2}) {
                for (ll dc : {-2, -1, 1, 2}) {
                    if (abs(dr) != abs(dc)) {
                        ll nr = i + dr;
                        ll nc = j + dc;
                        if (is_valid(nr, nc)) {
                            M.data[8*i + j][8*nr + nc] = 1;
                        }
                    }
                }
            }
        }
    }
    for (ll i = 0; i <= MN; ++i) {
        M.data[i][64] = 1;
    }
    Matrix result = exp(M, k + 1);
    cout << result.data[0][64];
    return 0;
}