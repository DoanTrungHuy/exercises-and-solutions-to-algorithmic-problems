# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        self.lst = [list(), list()]
        
        def dfs(root, l):
            if not root:
                return
            if not root.left and not root.right:
                l.append(root.val)
            dfs(root.left, l)
            dfs(root.right, l)
        
        dfs(root1, self.lst[0])
        dfs(root2, self.lst[1])
        
        return self.lst[0] == self.lst[1]