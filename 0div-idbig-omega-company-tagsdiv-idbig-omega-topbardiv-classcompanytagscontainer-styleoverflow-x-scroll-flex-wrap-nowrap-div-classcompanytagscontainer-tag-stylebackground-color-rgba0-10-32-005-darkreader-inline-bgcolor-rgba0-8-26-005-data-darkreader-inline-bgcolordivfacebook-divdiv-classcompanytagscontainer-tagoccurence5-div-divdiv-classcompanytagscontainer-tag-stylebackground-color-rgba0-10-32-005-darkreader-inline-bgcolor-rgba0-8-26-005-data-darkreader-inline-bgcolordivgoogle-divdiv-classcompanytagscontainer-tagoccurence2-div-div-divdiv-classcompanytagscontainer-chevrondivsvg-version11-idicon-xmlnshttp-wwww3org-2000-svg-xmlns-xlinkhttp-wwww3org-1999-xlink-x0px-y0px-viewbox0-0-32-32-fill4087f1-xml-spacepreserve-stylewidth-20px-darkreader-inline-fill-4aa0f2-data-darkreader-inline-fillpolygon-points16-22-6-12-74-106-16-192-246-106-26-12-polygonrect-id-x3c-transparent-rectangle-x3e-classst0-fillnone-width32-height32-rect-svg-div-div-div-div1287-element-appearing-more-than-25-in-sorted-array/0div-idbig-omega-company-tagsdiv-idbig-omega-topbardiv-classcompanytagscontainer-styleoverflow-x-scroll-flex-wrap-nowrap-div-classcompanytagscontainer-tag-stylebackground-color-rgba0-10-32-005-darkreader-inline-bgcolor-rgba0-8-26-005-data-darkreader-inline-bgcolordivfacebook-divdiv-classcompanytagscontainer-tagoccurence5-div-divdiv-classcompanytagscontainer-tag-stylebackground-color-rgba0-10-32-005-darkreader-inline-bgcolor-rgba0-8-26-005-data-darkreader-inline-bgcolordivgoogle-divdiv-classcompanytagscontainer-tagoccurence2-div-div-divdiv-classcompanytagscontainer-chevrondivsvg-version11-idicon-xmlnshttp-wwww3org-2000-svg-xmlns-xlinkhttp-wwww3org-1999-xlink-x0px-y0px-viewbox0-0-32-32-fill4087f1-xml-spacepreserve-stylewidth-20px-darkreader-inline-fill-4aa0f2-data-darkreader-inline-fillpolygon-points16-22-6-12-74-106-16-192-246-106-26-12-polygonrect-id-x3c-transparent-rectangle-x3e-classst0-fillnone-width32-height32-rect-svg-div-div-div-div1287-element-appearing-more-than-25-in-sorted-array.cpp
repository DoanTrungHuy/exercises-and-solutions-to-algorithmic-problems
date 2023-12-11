class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> um;
        const int n = arr.size();
        
        for (int num : arr) {
            um[num]++;
        }
        
        for (const auto [v, c] : um) {
            if (c > n / 4) {
                return v;
            }
        }
        
        return -1;
    }
};