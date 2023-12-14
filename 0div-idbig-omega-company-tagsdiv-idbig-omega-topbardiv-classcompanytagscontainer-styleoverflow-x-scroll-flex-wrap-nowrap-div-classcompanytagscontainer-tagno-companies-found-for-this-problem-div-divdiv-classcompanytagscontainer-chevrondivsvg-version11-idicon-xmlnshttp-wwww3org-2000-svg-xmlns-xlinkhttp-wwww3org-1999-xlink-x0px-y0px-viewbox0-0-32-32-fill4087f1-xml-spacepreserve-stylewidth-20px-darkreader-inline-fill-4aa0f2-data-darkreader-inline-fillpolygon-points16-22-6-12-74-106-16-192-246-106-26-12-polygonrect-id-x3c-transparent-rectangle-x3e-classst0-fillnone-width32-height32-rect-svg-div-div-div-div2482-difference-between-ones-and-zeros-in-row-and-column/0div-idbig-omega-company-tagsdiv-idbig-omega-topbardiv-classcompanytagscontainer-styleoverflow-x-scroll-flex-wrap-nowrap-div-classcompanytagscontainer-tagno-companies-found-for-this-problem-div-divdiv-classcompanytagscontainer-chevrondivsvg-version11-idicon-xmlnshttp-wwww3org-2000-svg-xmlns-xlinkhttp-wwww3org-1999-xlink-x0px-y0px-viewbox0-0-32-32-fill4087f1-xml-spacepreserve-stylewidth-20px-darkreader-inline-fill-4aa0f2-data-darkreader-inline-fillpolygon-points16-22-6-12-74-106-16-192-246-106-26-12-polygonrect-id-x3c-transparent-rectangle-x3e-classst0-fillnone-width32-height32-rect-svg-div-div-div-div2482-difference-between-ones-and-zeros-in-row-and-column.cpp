class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        
        int pref_one[2][n][m];
        memset(pref_one, 0, sizeof(pref_one));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j == 0) {
                    pref_one[0][i][j] = grid[i][j];
                }
                else {
                    pref_one[0][i][j] = pref_one[0][i][j - 1] + grid[i][j];
                }
            }
        }
        
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (i == 0) {
                    pref_one[1][i][j] = grid[i][j];
                }
                else {
                    pref_one[1][i][j] = pref_one[1][i - 1][j] + grid[i][j];
                }
            }
        }
        
        vector<vector<int>> ans(n, vector<int>(m));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] += pref_one[0][i][m - 1];
                ans[i][j] -= m - pref_one[0][i][m - 1];
                ans[i][j] += pref_one[1][n - 1][j];
                ans[i][j] -= n - pref_one[1][n - 1][j];
            }
        }
        
        return ans;
    }
};