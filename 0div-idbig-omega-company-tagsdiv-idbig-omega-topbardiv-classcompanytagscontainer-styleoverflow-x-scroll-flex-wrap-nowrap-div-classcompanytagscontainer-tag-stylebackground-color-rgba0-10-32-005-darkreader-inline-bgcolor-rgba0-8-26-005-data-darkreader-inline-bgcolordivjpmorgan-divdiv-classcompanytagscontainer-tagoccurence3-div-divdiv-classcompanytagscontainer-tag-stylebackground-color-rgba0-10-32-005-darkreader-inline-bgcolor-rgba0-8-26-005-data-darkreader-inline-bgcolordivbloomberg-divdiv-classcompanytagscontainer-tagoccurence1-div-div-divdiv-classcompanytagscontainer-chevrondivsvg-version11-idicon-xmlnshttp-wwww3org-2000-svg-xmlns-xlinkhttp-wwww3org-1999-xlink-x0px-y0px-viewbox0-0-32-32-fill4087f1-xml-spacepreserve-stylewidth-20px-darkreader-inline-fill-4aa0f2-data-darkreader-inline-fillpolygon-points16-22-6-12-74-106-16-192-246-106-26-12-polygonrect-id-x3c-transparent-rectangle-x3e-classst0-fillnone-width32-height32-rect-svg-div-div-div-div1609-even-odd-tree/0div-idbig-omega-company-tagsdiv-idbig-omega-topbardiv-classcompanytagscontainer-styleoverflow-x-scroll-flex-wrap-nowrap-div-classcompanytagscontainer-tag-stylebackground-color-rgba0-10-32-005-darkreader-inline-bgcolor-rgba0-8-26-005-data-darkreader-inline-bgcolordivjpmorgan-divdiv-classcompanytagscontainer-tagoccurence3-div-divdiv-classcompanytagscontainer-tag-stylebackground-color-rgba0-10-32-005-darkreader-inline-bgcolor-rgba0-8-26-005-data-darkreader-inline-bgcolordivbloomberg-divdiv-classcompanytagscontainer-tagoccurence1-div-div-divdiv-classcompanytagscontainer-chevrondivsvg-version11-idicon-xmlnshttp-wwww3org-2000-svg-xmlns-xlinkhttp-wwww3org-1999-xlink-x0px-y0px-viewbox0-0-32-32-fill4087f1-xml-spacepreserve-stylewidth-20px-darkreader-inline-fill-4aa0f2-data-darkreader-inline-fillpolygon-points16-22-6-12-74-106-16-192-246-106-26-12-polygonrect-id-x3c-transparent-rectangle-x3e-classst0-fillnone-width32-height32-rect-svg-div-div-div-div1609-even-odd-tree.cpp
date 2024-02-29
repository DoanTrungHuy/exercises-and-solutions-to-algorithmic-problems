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
public:
    bool isEvenOddTree(TreeNode* root) {
        bool isOdd = true;
        queue<TreeNode*> mq;
        mq.push(root);
        
        while (!mq.empty()) {
            int n = mq.size();
            int prev_val;
            if (isOdd) {
                prev_val = -1;
            }
            else {
                prev_val = 1e9;
            }
            while (n--) {
                TreeNode *curr = mq.front();
                mq.pop();
                if (isOdd) {
                    if (curr->val % 2 == 0) {
                        return false;
                    }
                    if (prev_val >= curr->val) {
                        return false;
                    }
                }
                else {
                    if (curr->val % 2 != 0) {
                        return false;
                    }
                    if (prev_val <= curr->val) {
                        return false;
                    }
                }
                prev_val = curr->val;
                if (curr->left) {
                    mq.push(curr->left);
                }
                if (curr->right) {
                    mq.push(curr->right);
                }
            }
            
            isOdd = !isOdd;
        }
        
        return true;
    }
};