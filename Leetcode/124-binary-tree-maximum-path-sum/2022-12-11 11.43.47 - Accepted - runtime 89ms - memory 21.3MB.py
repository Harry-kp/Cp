# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

    
    

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.ans = float('-inf')
        self.solve(root)
        return self.ans

    def solve(self,root):
        if not root:
            return 0
        
        ls,rs = self.solve(root.left),self.solve(root.right)

        single_path_sum = max(root.val+max(ls,rs), root.val)
        self.ans = max(self.ans, single_path_sum,ls+rs+root.val)
        return single_path_sum