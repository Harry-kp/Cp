class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n = g.size(),m = g[0].size();
        if(g[0][0] or g[n-1][m-1])
            return 0;
        int dp[n][m];
        dp[0][0] = 1;
        
        for(int i = 1;i<n;i++){
            dp[i][0] = !g[i][0]*dp[i-1][0];
        }
        for(int j = 1;j<m;j++){
            dp[0][j] = !g[0][j]*dp[0][j-1];
        }
        
        for(int i = 1;i<n;i++){
            for(int j = 1;j<m;j++){
                g[i][j]?(dp[i][j]=0):(dp[i][j] = dp[i-1][j]+dp[i][j-1]);
                    
            }
        }
        return dp[n-1][m-1];
    }
};