class Solution {
public:
  
    bool solve(int i,const vector<int>& nums,vector<int> bucket,const int& sum){
        
        
        if(i== 0){
            for(auto x:bucket)
                if(x!=sum)
                    return false;
            return true;
        }
        
        // if(dp.count(i) and dp[i].count(bucket))
        //     return dp[i][bucket];
        bool ans = false;
        for(int j = 0;j<bucket.size();j++){
            if(bucket[j]+nums[i-1]<=sum)
            {
                bucket[j]+=nums[i-1];
                ans|=solve(i-1,nums,bucket,sum);
                bucket[j]-=nums[i-1];
            }
        }
        return ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto x:nums)
            sum+=x;
        if(sum%k)return false;
        sum/=k;
        int n = nums.size();
        vector<int> b(k,0);
        return solve(n,nums,b,sum);
        
    }
};