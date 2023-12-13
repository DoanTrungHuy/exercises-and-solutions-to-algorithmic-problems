class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        const int n = mat.size(), m = mat[0].size();
        int cnt = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    continue;
                }
                bool flag = true;
                for (int k = 0; k < m; ++k) {
                    if (k == j) {
                        continue;
                    }
                    if (mat[i][k] == 1) {
                        flag = false;
                        break;
                    }
                }
                for (int k = 0; k < n; ++k) {
                    if (k == i) {
                        continue;
                    }
                    if (mat[k][j] == 1) {
                        flag = false;
                        break;
                    }
                }
                cnt += flag;
            }
        }
        
        return cnt;
    }
};