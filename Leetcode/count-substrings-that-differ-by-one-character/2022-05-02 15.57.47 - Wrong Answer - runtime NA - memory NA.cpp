class Solution {
public:
    int countSubstrings(string s, string t) {
            
        int n = s.size();
        int m = t.size();
        int dp[n+1][m+1];
        
        
        memset(dp,0,sizeof dp);
        
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+(s[i-1]!=t[j-1]);
            }
        }
        
        return dp[n][m];
    }
};