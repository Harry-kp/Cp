class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        seen = set()
        dp = {}
        MOD = 10**9+7
        def solve(i,j,move):
            
            if i<0 or j<0 or i == m or j == n:
                return 1
            if move == 0:
                return 0
            if (i,j,move) in dp:
                return dp[(i,j)]
            
            ans = (solve(i-1,j,move-1)+solve(i,j+1,move-1)+solve(i+1,j,move-1)+solve(i,j-1,move-1))%MOD
            dp[(i,j,move)] = ans
            return ans
        return solve(startRow,startColumn,maxMove)