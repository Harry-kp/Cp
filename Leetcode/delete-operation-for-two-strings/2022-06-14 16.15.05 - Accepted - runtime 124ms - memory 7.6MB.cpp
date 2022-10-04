class Solution {
public:
    int dp[501][501];
    int solve(int l,int r,const string& s1,const string& s2){
        if(l>=s1.size() or r>=s2.size())
            return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        if(s1[l]!=s2[r])
            return dp[l][r]=max(solve(l+1,r,s1,s2),solve(l,r+1,s1,s2));
        return dp[l][r]=1+solve(l+1,r+1,s1,s2);
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof dp);
        return word1.size()+word2.size()-2*solve(0,0,word1,word2);
    }
};