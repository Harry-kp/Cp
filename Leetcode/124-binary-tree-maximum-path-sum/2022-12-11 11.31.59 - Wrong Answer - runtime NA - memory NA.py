# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
ans = 0
def solve(root):
    global ans
    if not root:
        return 0
    
    max1 = solve(root.left)
    max2 = solve(root.right)

    ans = max(ans,max1+max2+root.val)
    return max(max1,max2)+root.val

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        x = solve(root)
        print(x,ans)
        return max(ans,x)