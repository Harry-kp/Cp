class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)

        dp = [defaultdict(int) for i in range(n)]
        ans = 0
        for i in range(n):
            for j in range(i):
                diff = nums[i]-nums[j]
                
                ans+=dp[j][diff]
                dp[i][diff]+=1+dp[j][diff]
        return ans



















            
            

