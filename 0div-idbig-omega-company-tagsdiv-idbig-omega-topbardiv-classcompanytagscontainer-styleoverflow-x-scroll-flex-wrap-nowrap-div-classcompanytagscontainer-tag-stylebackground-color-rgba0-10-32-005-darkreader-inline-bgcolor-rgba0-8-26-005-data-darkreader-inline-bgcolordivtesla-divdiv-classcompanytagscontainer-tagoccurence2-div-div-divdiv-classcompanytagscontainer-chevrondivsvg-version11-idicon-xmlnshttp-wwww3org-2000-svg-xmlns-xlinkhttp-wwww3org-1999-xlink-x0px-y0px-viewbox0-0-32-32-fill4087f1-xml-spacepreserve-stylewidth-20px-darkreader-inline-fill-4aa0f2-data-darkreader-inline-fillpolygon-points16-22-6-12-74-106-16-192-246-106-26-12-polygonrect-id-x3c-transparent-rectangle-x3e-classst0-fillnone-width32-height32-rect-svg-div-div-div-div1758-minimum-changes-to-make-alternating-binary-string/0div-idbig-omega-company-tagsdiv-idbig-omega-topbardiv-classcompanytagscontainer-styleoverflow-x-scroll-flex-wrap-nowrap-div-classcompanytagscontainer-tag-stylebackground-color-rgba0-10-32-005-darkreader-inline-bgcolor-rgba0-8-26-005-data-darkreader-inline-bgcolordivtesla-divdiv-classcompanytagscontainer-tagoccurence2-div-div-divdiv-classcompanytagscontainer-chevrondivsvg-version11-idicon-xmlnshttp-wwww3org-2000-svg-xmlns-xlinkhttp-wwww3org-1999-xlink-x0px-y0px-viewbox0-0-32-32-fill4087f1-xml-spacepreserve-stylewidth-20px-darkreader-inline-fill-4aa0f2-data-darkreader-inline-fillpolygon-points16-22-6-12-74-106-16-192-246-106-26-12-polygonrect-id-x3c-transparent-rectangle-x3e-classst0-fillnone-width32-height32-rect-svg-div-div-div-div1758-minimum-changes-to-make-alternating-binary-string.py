class Solution:
    def minOperations(self, s: str) -> int:
        cnt_case = [0]*2
        flag = ['0']*2
        flag[1] = '1'
        
        for c in s:
            cnt_case[0] += flag[0] == c
            flag[0] = '1' if flag[0] == '0' else '0'
            cnt_case[1] += flag[1] == c
            flag[1] = '1' if flag[1] == '0' else '0'
            
        return min(cnt_case)