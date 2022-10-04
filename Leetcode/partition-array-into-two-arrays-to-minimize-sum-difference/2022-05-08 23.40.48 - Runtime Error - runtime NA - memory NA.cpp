class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++)
            nums[i]+=1000000;
        int tot_sum = 0;
        for(auto x:nums)
            tot_sum+=x;
        int sum = tot_sum/2;
        
        int n = nums.size();
        int dp[n+1][sum+1];
        
        for(int j = 0;j<=sum;j++){
            dp[0][j] = 0;
        }
        for(int i = 0;i<=n;i++){
            dp[i][0] = 0;
        }
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=sum;j++){
                dp[i][j] = dp[i-1][j];
                
                if(j>=nums[i-1])
                    dp[i][j] = max(dp[i][j],dp[i-1][j-nums[i-1]] + nums[i-1]);
            }
        }
        return tot_sum - 2*dp[n][sum];
    }
};