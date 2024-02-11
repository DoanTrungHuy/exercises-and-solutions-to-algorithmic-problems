int memo[72][72][72];
vector<int> DIR = {-1, 0, 1};

class Solution {
private:
    vector<vector<int>> grid;
    int n, m;
    
public:
    bool is_valid(int y) {
        return 0 <= y and y < m;
    }
    
    int dp(int row, int rb1, int rb2) {
        if (row == n) {
            return 0;
        }
        if (memo[row][rb1][rb2] != -1) {
            return memo[row][rb1][rb2];
        }
        int ans = 0;
        for (int i : DIR) {
            for (int j : DIR) {
                int n_rb1 = rb1 + i;
                int n_rb2 = rb2 + j;
                if (is_valid(n_rb1) and is_valid(n_rb2) and n_rb1 != n_rb2) {
                    ans = max(ans, grid[row][rb1] + grid[row][rb2] + dp(row + 1, n_rb1, n_rb2));
                }
            }
        }
        return memo[row][rb1][rb2] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        this->grid = grid;
        this->n = grid.size();
        this->m = grid[0].size();
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, m - 1);
    }
};