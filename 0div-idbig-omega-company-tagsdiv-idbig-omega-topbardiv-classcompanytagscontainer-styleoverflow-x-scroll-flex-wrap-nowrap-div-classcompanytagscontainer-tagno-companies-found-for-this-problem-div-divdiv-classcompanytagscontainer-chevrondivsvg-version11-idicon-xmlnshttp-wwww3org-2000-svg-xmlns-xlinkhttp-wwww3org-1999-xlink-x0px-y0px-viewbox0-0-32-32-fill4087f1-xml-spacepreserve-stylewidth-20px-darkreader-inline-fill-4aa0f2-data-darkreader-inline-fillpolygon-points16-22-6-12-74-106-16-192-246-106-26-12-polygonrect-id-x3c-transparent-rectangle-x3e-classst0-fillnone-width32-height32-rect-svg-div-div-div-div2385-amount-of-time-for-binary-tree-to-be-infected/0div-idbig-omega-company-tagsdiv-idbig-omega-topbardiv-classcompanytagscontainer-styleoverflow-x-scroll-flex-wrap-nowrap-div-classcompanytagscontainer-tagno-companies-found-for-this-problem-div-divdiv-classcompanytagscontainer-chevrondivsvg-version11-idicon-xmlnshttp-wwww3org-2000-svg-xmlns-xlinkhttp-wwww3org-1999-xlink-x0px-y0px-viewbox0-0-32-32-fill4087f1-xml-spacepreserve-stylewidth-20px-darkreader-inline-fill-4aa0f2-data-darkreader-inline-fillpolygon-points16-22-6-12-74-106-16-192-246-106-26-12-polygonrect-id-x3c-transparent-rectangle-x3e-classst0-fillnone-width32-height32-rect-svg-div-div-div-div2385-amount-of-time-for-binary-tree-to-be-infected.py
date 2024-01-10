# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        self.adj = defaultdict(list)
        
        def dfs(root):
            if not root:
                return
            
            if root.left:
                self.adj[root.val].append(root.left.val)
                self.adj[root.left.val].append(root.val)
                
            if root.right:
                self.adj[root.val].append(root.right.val)
                self.adj[root.right.val].append(root.val)
                
            dfs(root.left)
            dfs(root.right)
            
        dfs(root)
        
        self.visited = set()
        
        def depth_max(u):
            self.visited.add(u)
            ans = 0
            for v in self.adj[u]:
                if v not in self.visited:
                    ans = max(ans, 1 + depth_max(v))
            return ans
            
        return depth_max(start)