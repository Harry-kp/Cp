class Solution {
public:
    int dp[205][205];
    int solve(int r,int c,const vector<vector<int>>& triangle){
        if(r == triangle.size())
            return 0;
        
        if(c>=triangle[r].size())
            return 1000000000;
        if(dp[r][c]!=-1)return dp[r][c];
        return dp[r][c]=triangle[r][c] + min(solve(r+1,c,triangle),solve(r+1,c+1,triangle));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,triangle);
    }
};