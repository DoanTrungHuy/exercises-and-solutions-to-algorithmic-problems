class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> pref;
        pref[0] = 1;
        int sum = 0, ans = 0;
        
        for (int num : nums) {
            sum += num;
            ans += pref[sum - k];
            pref[sum]++;
        }
        
        return ans;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            vector<int> dp(m, 0);
            for (int j = i; j < n; ++j) {
                for (int k = 0; k < m; ++k) {
                    dp[k] += matrix[j][k];
                }
                ans += subarraySum(dp, target);
            }
        }
        
        return ans;
    }
};