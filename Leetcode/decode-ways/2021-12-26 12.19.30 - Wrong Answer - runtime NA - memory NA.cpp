class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.size();
        vector<int> dp(n+1,0);
        
        //base case 
        if(s[0] == 0)return 0;
        
        dp[0] = dp[1] = 1;
        for(int i = 2;i<=n;i++){
            
            int j = i-1;
            if(s[j]!='0'){
                dp[i] = dp[i-1];
            }
            
            if((s[j-1] == '1' or s[j-1] == '2') and s[j]<'7')
                dp[i]+=dp[i-2];
            
        }
        // for(int i = 0;i<=n;i++)
                // cout<<dp[i]<<'\n';
        return dp[n];
    }
};