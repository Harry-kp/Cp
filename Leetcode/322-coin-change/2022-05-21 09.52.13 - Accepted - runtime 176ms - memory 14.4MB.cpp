class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1000000);
        
        dp[0] = 0;
        for(int i = 0;i<coins.size();i++){
            for(int j = coins[i];j<=amount;j++){
                dp[j] = min(dp[j],1+dp[j-coins[i]]);
            }
        }
        return dp[amount] == 1000000?-1:dp[amount];
    }
};