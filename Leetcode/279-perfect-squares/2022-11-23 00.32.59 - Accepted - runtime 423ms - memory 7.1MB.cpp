class Solution {
public:
    int numSquares(int n) {
        
        vector<int> coins;
        for(int i = 1;i<=100;i++){
            coins.push_back(i*i);
        }
        
        int dp[n+1];
        fill(dp,dp+n+1,100000);
        dp[0] = 0;
        for(int i = 0;i<=n;i++){
            for(int j = 0;coins[j]<=i and j<coins.size();j++){
                dp[i] = min(dp[i],dp[i-coins[j]]+1);
            }
        }
        return dp[n];
    }
};