class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:return 1
        a = 1
        b = 2
        for i in range(3,n+1):
            c = b
            b = a+b
            a = c
        return b



        

