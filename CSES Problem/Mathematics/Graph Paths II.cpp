#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
ll N, M, K;
const ll MOD = 1e9 + 7;
const ll INF = 4e18;
 
struct Matrix {
    ll row, col;
    vector<vector<ll>> mat;
 
    Matrix(ll row, ll col, ll v = INF) {
        this->row = row;
        this->col = col;
        mat.resize(row, vector<ll>(col, v));
    }
 
    static Matrix identity(ll n) {
        Matrix T(n, n);
        for (ll i = 0; i < n; ++i) {
            T.mat[i][i] = 0;
        }
        return T;
    }
 
    Matrix operator * (Matrix B) {
        Matrix A = *this;
        Matrix C(A.row, B.col);
        for (ll i = 0; i < A.row; ++i) {
            for (ll j = 0; j < B.col; ++j) {
                for (ll k = 0; k < A.col; ++k) {
                    C.mat[i][j] = min(C.mat[i][j], A.mat[i][k] + B.mat[k][j]);
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
    cin >> N >> M >> K;
    Matrix base(N, N);
    for (ll i = 0; i < M; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        base.mat[a][b] = min(base.mat[a][b], c);
    }
    Matrix res = exp(base, K);
    if (res.mat[0][N - 1] == INF) {
        cout << -1;
    }
    else {
        cout << res.mat[0][N - 1];
    }
    return 0;
}