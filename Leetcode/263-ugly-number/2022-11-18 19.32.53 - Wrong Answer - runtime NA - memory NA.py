# import math
class Solution:
    def isUgly(self, n: int) -> bool:
        if n<0:return False 
        for i in range(2,int(math.sqrt(n))+1):
            while n%i == 0:
                if i not in [2,3,5]:return False
                n//=i
        if n>2:
             if n not in [2,3,5]:return False
        return True