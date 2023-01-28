# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def solve(root,ans):
    if root is None:
        return 
    solve(root.left,ans)
    solve(root.right,ans)
    if root.left is None and root.right is None:
        ans.append(root.val)
class Solution:
    

    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        ans1 = []
        ans2 = []

        solve(root1,ans1)
        solve(root2,ans2)
        return ans1 == ans2