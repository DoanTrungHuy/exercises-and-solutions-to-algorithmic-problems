#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

const ll MOD = 1e9 + 7;

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

class Solution {
public:
    ll nthFibonacci(ll n){
        if (n == 0) {
            return 0;
        }
        Matrix M(2, 2);
        M.data = {
          {1, 1},
          {1, 0}
        };
        Matrix base(2, 1);
        base.data = {
            {1},
            {0}
        };
        Matrix result = exp(M, n - 1) * base;
        return result.data[0][0];
    }
};

int main() {
    ll n;
    cin >> n;
    Solution ob;
    cout << ob.nthFibonacci(n);
    return 0;
}