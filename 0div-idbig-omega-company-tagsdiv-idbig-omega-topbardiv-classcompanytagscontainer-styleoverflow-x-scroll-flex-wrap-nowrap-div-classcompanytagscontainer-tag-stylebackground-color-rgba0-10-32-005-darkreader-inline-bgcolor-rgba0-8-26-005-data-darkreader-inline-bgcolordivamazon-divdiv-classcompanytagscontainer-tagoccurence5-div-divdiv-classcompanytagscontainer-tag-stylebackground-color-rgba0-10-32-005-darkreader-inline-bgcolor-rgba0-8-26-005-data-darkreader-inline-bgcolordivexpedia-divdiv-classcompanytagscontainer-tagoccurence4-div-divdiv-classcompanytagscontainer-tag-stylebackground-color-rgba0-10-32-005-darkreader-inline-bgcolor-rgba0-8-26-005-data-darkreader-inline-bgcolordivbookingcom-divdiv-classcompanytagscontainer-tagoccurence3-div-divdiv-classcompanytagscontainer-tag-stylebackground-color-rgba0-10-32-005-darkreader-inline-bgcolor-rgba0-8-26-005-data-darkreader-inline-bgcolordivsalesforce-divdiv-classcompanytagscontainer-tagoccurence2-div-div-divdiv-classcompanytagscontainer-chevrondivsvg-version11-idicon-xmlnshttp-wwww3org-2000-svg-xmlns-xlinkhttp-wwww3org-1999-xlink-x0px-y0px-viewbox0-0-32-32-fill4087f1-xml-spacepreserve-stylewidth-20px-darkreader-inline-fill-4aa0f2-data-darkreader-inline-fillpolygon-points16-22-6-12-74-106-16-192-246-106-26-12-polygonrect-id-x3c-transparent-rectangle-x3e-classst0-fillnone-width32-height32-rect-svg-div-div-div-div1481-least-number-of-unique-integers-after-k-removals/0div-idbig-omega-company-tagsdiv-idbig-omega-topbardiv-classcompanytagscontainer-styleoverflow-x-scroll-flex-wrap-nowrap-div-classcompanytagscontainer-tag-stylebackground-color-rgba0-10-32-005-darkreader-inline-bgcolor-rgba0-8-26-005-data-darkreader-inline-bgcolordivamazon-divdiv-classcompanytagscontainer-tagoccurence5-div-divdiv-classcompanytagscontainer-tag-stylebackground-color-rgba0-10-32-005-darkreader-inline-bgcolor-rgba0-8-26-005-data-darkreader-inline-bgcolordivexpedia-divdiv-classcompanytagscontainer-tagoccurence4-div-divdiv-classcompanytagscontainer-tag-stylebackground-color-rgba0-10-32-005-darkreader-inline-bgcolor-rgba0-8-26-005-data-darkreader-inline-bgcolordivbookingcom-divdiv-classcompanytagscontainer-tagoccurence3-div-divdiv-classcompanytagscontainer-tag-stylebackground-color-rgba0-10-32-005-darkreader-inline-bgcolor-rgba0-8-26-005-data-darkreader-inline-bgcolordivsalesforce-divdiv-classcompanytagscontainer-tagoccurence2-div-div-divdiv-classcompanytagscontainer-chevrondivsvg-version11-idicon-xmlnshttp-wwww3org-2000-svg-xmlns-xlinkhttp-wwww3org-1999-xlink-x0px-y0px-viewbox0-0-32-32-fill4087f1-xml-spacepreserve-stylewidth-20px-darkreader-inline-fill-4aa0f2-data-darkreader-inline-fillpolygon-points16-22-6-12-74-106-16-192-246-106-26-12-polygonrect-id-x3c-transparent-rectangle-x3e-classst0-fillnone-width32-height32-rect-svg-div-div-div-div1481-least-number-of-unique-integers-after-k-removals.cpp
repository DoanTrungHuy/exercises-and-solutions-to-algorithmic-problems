class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> cnt;
        
        for (int num : arr) {
            cnt[num]++;
        }
        
        vector<int> nums;
        
        int ans = cnt.size();
        
        for (auto [num, cnt_num] : cnt) {
            nums.push_back(cnt_num);
        }
        
        sort(nums.begin(), nums.end());
        
        for (int cnt_num : nums) {
            if (k - cnt_num < 0) {
                break;
            }
            ans--;
            k -= cnt_num;
        }
        
        return ans;
    }
};