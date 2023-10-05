#include <bits/stdc++.h>

using namespace std;

using ll = long long;
ll t, n, k;
ll b[11], c[11];
const ll MOD = 1e9;

struct Matrix {
    ll row, col;
    vector<vector<ll>> data;

    Matrix(ll row = 0, ll col = 0) {
        this->row = row;
        this->col = col;
        data.resize(row, vector<ll>(col, 0));
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
                    C.data[i][j] = (C.data[i][j] + (A.data[i][k] * B.data[k][j]) % MOD) % MOD;
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
    cin >> t;
    while (t--) {
        cin >> k;
        for (ll i = 1; i <= k; ++i) {
            cin >> b[i];
        }
        for (ll i = 1; i <= k; ++i) {
            cin >> c[i];
        }
        cin >> n;
        if (n <= k) {
            cout << b[n] % MOD << '\n';
            continue;
        }
        Matrix D(k, k);
        for (ll i = 1; i <= k; ++i) {
            D.data[0][i - 1] = c[i];
        }
        for (ll i = 1; i <= k - 1; ++i) {
            D.data[i][i - 1] = 1;
        }
        Matrix base(k, 1);
        for (ll i = 1; i <= k; ++i) {
            base.data[i - 1][0] = b[k - i + 1];
        }
        Matrix result = exp(D, n - k) * base;
        cout << result.data[0][0] << '\n';
    }
    return 0;
}