class Solution {
public:
  
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto x:nums)
            sum+=x;
        if(sum%k)return false;
        sum/=k;
        int n = nums.size();
       
        //dp with bitmasks
        
        int dp[(1<<n)];
        memset(dp,-1,sizeof dp);
        for(int i = 0;i<n;i++){
            if(nums[i]<=sum)
                dp[(1<<i)] = nums[i]%sum;
        }
        for(int mask = 0;mask<(1<<n);mask++){
            if(dp[mask]==-1)continue;
            
            for(int j = 0;j<n;j++){
                if(!(mask&(1<<j)) and dp[mask]+nums[j]<=sum)
                    dp[mask|(1<<j)] = (dp[mask]+nums[j])%sum;
            }
        }
        
        return dp[(1<<n)-1]==0;
        
    }
};