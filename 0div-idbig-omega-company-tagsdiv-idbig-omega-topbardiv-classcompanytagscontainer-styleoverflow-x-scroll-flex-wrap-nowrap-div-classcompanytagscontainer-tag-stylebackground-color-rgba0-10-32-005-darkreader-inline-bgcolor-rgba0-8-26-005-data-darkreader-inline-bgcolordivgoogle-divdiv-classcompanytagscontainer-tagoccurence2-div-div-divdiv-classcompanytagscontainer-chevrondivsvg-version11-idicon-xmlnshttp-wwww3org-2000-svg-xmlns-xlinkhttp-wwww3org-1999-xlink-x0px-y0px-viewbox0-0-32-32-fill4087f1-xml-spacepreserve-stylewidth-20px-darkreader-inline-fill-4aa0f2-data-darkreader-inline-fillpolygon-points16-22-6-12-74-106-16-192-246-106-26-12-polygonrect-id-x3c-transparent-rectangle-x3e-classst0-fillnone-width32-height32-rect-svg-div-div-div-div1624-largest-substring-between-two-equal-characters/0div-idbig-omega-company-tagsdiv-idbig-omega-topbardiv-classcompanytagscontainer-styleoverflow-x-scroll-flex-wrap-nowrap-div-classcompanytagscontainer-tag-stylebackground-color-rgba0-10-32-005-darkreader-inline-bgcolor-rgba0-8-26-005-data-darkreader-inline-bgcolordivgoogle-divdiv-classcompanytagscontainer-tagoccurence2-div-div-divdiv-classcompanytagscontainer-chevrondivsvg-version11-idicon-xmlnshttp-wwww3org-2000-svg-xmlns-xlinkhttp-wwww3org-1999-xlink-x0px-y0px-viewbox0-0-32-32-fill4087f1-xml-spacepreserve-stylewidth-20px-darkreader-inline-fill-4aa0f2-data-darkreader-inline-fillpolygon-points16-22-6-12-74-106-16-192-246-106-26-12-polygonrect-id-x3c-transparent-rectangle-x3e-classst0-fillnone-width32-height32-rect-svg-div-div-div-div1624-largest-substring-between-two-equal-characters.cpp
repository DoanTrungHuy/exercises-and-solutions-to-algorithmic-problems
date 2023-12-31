class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int idx[26] = {0};
        int res = -1;
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            if (idx[s[i] - 'a'] == 0) {
                idx[s[i] - 'a'] = i + 1;
            }
            res = max(res, i - idx[s[i] - 'a']);
        }
        
        return res;
    }
};