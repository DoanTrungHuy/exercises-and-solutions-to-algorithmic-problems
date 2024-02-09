class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        vector<int> dp(n, 1);
        int maxLen = 0;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        
        int j = 0;
        
        for (int i = n - 1; i >= 0; --i) {
            if (dp[i] == maxLen) {
                j = i;
                break;
            }
        }
        
        vector<int> ans = {nums[j]};
        j--, maxLen--;
        
        for (int i = j; i >= 0; --i) {
            if (dp[i] == maxLen and ans.back() % nums[i] == 0) {
                ans.push_back(nums[i]);
                maxLen--;
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};