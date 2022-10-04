class Solution {
public:
    int dp[55][6];
    int solve(int i,int pre,int &n){
        if(i>=n)
            return 0;
        if(dp[i][pre]!=-1)return dp[i][pre];
        
        int ans = 0;
        for(int j = pre;j<=4;j++){
            ans+=1 + solve(i+1,j,n);
        }
        return dp[i][pre]=ans;
    }
    
    int countVowelStrings(int n) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,n);
    }
};