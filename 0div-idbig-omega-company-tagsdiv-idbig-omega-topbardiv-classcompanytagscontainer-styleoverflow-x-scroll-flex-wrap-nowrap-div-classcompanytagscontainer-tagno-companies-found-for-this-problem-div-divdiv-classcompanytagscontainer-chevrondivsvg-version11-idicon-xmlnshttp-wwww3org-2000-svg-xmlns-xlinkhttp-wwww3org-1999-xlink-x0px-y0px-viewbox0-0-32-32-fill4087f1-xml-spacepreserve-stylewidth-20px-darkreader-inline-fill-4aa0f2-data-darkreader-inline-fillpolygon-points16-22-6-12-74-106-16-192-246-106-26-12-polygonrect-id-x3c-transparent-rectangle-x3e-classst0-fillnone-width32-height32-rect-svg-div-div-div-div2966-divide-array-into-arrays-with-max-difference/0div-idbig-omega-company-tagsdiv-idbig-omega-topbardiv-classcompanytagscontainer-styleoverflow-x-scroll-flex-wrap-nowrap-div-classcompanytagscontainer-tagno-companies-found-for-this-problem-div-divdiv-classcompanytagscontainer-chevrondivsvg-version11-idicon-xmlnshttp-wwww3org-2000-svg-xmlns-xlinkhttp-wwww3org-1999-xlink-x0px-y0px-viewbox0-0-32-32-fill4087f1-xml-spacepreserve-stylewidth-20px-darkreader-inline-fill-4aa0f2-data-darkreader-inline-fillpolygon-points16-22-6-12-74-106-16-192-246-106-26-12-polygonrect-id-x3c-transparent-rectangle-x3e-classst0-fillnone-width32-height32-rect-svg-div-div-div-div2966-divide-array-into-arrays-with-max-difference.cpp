class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        const int n = nums.size();
        if (n % 3 != 0) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        
        for (int i = 0; i < n - 1; i += 3) {
            int cnt = 0;
            int minEle = INT_MAX;
            int maxEle = INT_MIN;
            for (int j = 0; j < 2; ++j) {
                minEle = min({minEle, nums[i + j + 1], nums[i + j]});
                maxEle = max({maxEle, nums[i + j + 1], nums[i + j]});
                if (maxEle - minEle <= k) {
                    cnt++;
                }
            }
            if (cnt != 2) {
                return {};
            }
        }
        
        int sz = 0;
        
        for (int i = 0; i < n; ++i) {
            sz++;
            tmp.push_back(nums[i]);
            if (sz == 3) {
                sz = 0;
                ans.push_back(tmp);
                tmp.clear();
            }
        }
        
        return ans;
    }
};