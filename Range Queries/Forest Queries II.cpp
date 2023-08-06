#include <iostream>
 
using namespace std;
 
const int MAXN = 1001;
int mat[MAXN][MAXN];
int bit[MAXN][MAXN];
int n, q;
 
void update(int i, int j, int v) {
    for (; i <= n; i += i&-i) {
        for (int jj = j; jj <= n; jj += jj&-jj) {
            bit[i][jj] += v;
        }
    }
}
 
int get_sum(int i, int j) {
    int ans = 0;
    for (; i > 0; i -= i&-i) {
        for (int jj = j; jj > 0; jj -= jj&-jj) {
            ans += bit[i][jj];
        }
    }
    return ans;
}
 
int main()
{
    cin >> n >> q;
    string s[n];
    
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < n; ++j) {
            int x = i + 1, y = j + 1;
            mat[x][y] = int(s[i][j] == '*');
            update(x, y, mat[x][y]);
        }
    }
    
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            mat[x][y] ^= 1;
            update(x, y, mat[x][y] == 0 ? -1 : 1);
        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << get_sum(x2, y2) - get_sum(x2, y1 - 1) - get_sum(x1 - 1, y2) + get_sum(x1 - 1, y1 - 1) << '\n';
        }
    }
    
    return 0;
}