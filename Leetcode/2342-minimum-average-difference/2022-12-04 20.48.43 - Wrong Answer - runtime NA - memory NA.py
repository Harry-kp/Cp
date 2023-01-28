class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        n = len(nums)
        prefix = nums
        for i in range(1,n):
            prefix[i]+=prefix[i-1]
        
        cdiff = 1000000000000
        ans = 0
        for i in range(n-1):
            diff = abs(prefix[i]//(i+1) - (prefix[n-1]- prefix[i])//(n-i-1))

            if diff < cdiff:
                cdiff = diff
                ans = i
        return ans



        