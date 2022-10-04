class Solution {
public:
    int countSubstrings(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        int dp[n+1][m+1][2];
        memset(dp,0,sizeof dp);
        int ans = 0;
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j][0] = 1+dp[i-1][j-1][0];
                    dp[i][j][1] = dp[i-1][j-1][1];
                }else
                {
                    dp[i][j][1] = 1+dp[i-1][j-1][0];
                }
                ans+=dp[i][j][1];
                    
        }
    }
        return ans;
    }
};