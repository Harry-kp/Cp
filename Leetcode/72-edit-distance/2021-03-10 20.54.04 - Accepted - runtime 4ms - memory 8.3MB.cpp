class Solution {
public:
    
    long long int min(long long int x,long long int y){
        return x<y?x:y;
    }
    int minDistance(string a, string b) {
    long long int i,j,na,nb;
    
    na = a.size();
    nb = b.size();
    long long int dp[na+1][nb+1];
    for(i = 0;i<=na;i++)
        for(j = 0;j<=nb;j++){
            if (i == 0)dp[i][j] = j;
            else if(j == 0)dp[i][j] = i;
            else dp[i][j] = min(min(dp[i-1][j] + 1,dp[i][j-1] + 1),dp[i-1][j-1] + (a[i-1] == b[j-1]?0:1));
        }
    return dp[na][nb];
            
    }
};