class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if (n != m) {
            return false;
        }
        int cnt1[26] = {0}, cnt2[26] = {0};
        for (char c : word1) {
            cnt1[c - 'a']++;
        }
        for (char c : word2) {
            cnt2[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            if ((cnt1[i] and !cnt2[i]) or (cnt2[i] and !cnt1[i])) {
                return false;
            }
        }
        sort(cnt1, cnt1 + 26);
        sort(cnt2, cnt2 + 26);
        for (int i = 0; i < 26; ++i) {
            if (cnt1[i] != cnt2[i]) {
                return false;
            }
        }
        return true;
    }
};