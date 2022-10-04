class Solution:
    def sumZero(self, n: int) -> List[int]:
        ans = [0]*n
        
        for i in range(1,n):
            ans[i] = i
        ans[0] = ((n-1)*n)//2
        ans[0]*=-1
        return ans
            
            
        