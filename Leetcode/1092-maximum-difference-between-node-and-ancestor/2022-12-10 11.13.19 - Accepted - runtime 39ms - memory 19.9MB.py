def solve(root,min1,max1,ans):
    if root is None:
        return
    
    ans[0] = max(ans[0],abs(root.val-min1),abs(root.val-max1))

    min1 = min(root.val,min1)
    max1 = max(root.val,max1)

    solve(root.left,min1,max1,ans)
    solve(root.right,min1,max1,ans)
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        ans = [0]
        solve(root,root.val,root.val,ans)
        return ans[0]
        