class Solution {
public:
    int solve(int i,int j,const string& a,const string& b,vector<vector<int>>& dp){
        if(i<0 or j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = 0;
        
        if(a[i] == b[j]){
            int tmp = 1+solve(i-1,j-1,a,b,dp);
            ans = max(ans,tmp);
        }else{
            ans = max(ans,solve(i-1,j,a,b,dp));
            ans = max(ans,solve(i,j-1,a,b,dp));
        }
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+2,vector<int>(text2.size()+2,-1));
        return solve(text1.size()-1,text2.size()-1,text1,text2,dp);
    }
};