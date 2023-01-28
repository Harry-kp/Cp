class Solution {
public:
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        
        int dp[n][n];
        
        //base case
        for(int i = 0;i<n;i++){
            dp[i][i] = ((i == 0)?1:nums[i-1]) * nums[i] * ((i == n-1)?1:nums[i+1]);
        }
        
        for(int l = 2;l<=n;l++){
            for(int i = 0;i<=n-l;i++){
                int j = i+l-1;
                // cout<<i<<" "<<j<<'\n';
                dp[i][j] = 0;
                for(int k = i;k<=j;k++){
                    
                    int a = 0,b = nums[k],c = 0;
                    
                    if(k!=i)a = dp[i][k-1];
                    if(k!=j)c = dp[k+1][j];
                    
                    if(i!=0)b*=nums[i-1];
                    if(j!=n-1)b*=nums[j+1];
                    
                    dp[i][j] = max(dp[i][j],a+b+c);
                }
            }
        }
        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }
        return dp[0][n-1];
        
    }
};

// 0 -- 1 --- 2 -- 3