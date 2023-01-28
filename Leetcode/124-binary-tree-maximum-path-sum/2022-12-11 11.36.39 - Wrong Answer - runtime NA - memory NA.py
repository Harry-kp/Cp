# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def solve(root,ans):
    if not root:
        return -999999999999
    
    max1 = solve(root.left,ans)
    max2 = solve(root.right,ans)

    ans[0] = max(ans[0],max1,max2,max(max1,max2)+root.val,max1+max2+root.val)
    return max(max1,max2)+root.val

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        ans = [-99999999999]
        x = solve(root,ans)
        return max(ans[0],x)