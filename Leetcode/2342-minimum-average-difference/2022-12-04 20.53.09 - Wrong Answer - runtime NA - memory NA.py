class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        n = len(nums)
        prefix = nums
        for i in range(1,n):
            prefix[i]+=prefix[i-1]
        
        cdiff = 1234567890567
        ans = 0
        for i in range(n-1):
            diff = abs(prefix[i]//(i+1) - (prefix[n-1]- prefix[i])//(n-i-1))

            if diff < cdiff:
                cdiff = diff
                ans = i
        return ans if prefix[n-1]//n > cdiff else n-1



        