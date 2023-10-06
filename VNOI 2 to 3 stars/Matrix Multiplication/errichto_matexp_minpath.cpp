#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m, k;
const ll INF = 2e18L + 5;

struct Matrix {
    ll row, col;
    vector<vector<ll>> data;

    Matrix(ll row = 0, ll col = 0) {
        this->row = row;
        this->col = col;
        data.resize(row, vector<ll>(col, INF));
    }

    static Matrix identity(ll n) {
        Matrix M(n, n);
        for (ll i = 0; i < n; ++i) {
            M.data[i][i] = 0;
        }
        return M;
    }

    Matrix operator * (Matrix B) {
        Matrix A = *this;
        Matrix C(A.row, B.col);
        for (ll i = 0; i < A.row; ++i) {
            for (ll j = 0; j < B.col; ++j) {
                for (ll k = 0; k < A.col; ++k) {
                    C.data[i][j] = min(C.data[i][j], A.data[i][k] + B.data[k][j]);
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
        ll u, v, w;
        cin >> u >> v >> w;
        M.data[u - 1][v - 1] = w;
    }
    Matrix base(n, 1);
    for (ll i = 0; i < n; ++i) {
        base.data[i][0] = 0;
    }
    Matrix result = exp(M, k) * base;
    ll ans = INF;
    for (ll i = 0; i < n; ++i) {
        ans = min(ans, result.data[i][0]);
    }
    if (ans >= (INF / 2)) {
        cout << "IMPOSSIBLE";
    }
    else {
        cout << ans;
    }
    return 0;
}