#include <bits/stdc++.h>

using namespace std;

using ll = long long;
ll n;
double p;

struct Matrix {
    ll row, col;
    vector<vector<double>> data;

    Matrix(ll row = 0, ll col = 0) {
        this->row = row;
        this->col = col;
        data.resize(row, vector<double>(col, 0));
    }

    static Matrix indentity(ll n) {
        Matrix m(n, n);
        for (ll i = 0; i < n; ++i) {
            m.data[i][i] = 1;
        }
        return m;
    }

    Matrix operator * (Matrix &B) {
        Matrix A = *this;
        Matrix C(A.row, B.col);
        for (ll i = 0; i < A.row; ++i) {
            for (ll j = 0; j < B.col; ++j) {
                for (ll k = 0; k < A.col; ++k) {
                    C.data[i][j] = C.data[i][j] + A.data[i][k] * B.data[k][j];
                }
            }
        }
        return C;
    }
};

Matrix exp(Matrix &a, ll b) {
    if (b == 0) {
        return Matrix::indentity(a.col);
    }
    Matrix res = exp(a, b / 2);
    res = res*res;
    if (b & 1) {
        res = res*a;
    }
    return res;
}

int main() {
    cin >> n >> p;
    Matrix M(2, 2);
    M.data = {
        {1 - p, p},
        {p, 1 - p}
    };
    Matrix result = exp(M, n);
    cout << fixed << setprecision(6) << result.data[0][0];
    return 0;
}