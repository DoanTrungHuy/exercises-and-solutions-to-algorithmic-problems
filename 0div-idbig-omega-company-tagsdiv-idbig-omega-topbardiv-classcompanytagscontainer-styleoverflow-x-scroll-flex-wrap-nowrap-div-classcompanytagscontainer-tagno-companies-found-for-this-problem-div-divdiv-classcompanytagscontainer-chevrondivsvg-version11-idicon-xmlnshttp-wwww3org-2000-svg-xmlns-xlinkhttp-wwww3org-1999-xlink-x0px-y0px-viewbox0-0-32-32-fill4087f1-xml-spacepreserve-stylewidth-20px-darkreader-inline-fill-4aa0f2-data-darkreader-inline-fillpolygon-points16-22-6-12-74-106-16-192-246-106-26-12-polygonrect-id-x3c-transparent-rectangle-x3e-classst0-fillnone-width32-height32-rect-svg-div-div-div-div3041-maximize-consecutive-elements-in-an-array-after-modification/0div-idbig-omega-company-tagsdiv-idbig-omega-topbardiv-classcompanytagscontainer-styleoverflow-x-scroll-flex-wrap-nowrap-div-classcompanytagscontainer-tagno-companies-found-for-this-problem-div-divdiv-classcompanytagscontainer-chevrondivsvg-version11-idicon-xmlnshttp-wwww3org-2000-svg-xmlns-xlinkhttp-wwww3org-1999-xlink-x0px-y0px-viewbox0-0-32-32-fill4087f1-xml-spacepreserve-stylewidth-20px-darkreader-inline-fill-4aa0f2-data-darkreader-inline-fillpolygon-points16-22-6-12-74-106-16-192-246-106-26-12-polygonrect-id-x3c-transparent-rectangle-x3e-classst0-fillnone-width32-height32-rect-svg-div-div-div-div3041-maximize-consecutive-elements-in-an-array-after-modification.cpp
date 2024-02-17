class Solution {
private:
    vector<int> nums;
    int n;
    vector<unordered_map<int, int>> memo;
    
public:
    int dp(int i, int prev) {
        if (i == n) {
            return 0;
        }
        if (memo[i].count(prev)) {
            return memo[i][prev];
        }
        int ans = 0;
        if (nums[i] == prev + 1) {
            ans = max(ans, 1 + dp(i + 1, nums[i]));
        }
        if (nums[i] + 1 == prev + 1) {
            ans = max(ans, 1 + dp(i + 1, nums[i] + 1));
        }
        if (nums[i] + 1 == prev) {
            ans = max(ans, dp(i + 1, nums[i] + 1));
        }
        return memo[i][prev] = ans;
    }
    
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        this->n = nums.size();
        int ans = 0;
        memo.resize(n);
        for (int i = 0; i < n; ++i) {
            ans = max(ans, 1 + dp(i + 1, nums[i]));
            ans = max(ans, 1 + dp(i + 1, nums[i] + 1));
        }
        return ans;
    }
};