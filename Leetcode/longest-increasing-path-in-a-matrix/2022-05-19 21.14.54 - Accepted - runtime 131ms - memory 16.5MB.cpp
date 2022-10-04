class Solution {
public:
    int dfs(int i,int j,int p,vector<vector<int>>& mat,vector<vector<int>>& dp){
        
        int m = mat.size();
        int n = mat[0].size();
        if(i<0 or j<0 or i>=m or j>=n or mat[i][j]<=p)
            return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        int l = dfs(i,j-1,mat[i][j],mat,dp);
        int r = dfs(i,j+1,mat[i][j],mat,dp);
        int t = dfs(i-1,j,mat[i][j],mat,dp);
        int b = dfs(i+1,j,mat[i][j],mat,dp);
        
        return dp[i][j] = max({l,r,t,b})+1;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        int ans = 0;
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                ans = max(ans,dfs(i,j,-1,mat,dp));
            }
        }
        return ans;
    }
};