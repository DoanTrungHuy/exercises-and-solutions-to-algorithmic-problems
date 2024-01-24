/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    unordered_map<int, int> cnt;
    int res = 0;
    
public:
    void dfs(TreeNode *root) {
        if (!root) {
            return;
        }
        
        cnt[root->val]++;
        
        if (!root->left and !root->right) {
            int cntOdd = 0;
            for (auto [_, value] : cnt) {
                if (value & 1) 
                {
                    cntOdd++;
                }
            }
            if (cntOdd <= 1) {
                res++;
            }
        }
        
        dfs(root->left), dfs(root->right);
        
        cnt[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return res;
    }
};