def solve(root, minn, maxx, res):
    if not root: 
        return
    
    res[0] = max(res[0], abs(minn - root.val), abs(maxx - root.val))

    minn = min(root.val, minn)
    maxx = max(maxx, root.val)

    solve(root.left, minn, maxx, res)
    solve(root.right, minn, maxx, res)
    
class Solution(object):
    def maxAncestorDiff(self, root):
        if not root:
            return 0
        res = [0]
        solve(root, root.val, root.val, res)
        return res[0]