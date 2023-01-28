def solve(root,dict1):
    if not root:
        return 0
    
    ans = root.val+solve(root.left,dict1)+solve(root.right,dict1)
    dict1.append(ans)
    return ans

class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        dict1 = []
        solve(root,dict1)
        max1 = 0
        for i in dict1:
            max1 = max(max1,i*abs(i-dict1[-1]))
        print(dict1)
        return max1%1000000007