class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        seen = set()
        dp = {}
        MOD = 10**9+7
        def solve(i,j,move,ii,jj):
            if move<0:
                return 0
            if i<0 or j<0 or i == m or j == n:
                return 1
            
            if (i,j) in dp:
                return dp[(i,j)]
            ans = 0
            if i-1!=ii or j!=jj:
                ans = (ans + solve(i-1,j,move-1,i,j))%MOD
            if i!=ii or j+1!=jj:
                ans = (ans + solve(i,j+1,move-1,i,j))%MOD
            if i+1!=ii or j!=jj:
                ans = (ans + solve(i+1,j,move-1,i,j))%MOD
            if i!=ii or j-1!=jj:
                ans = (ans + solve(i,j-1,move-1,i,j))%MOD
            dp[(i,j)] = ans
            return ans
        return solve(startRow,startColumn,maxMove,-1,-1)