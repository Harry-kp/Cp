class Solution {
public:
    
    int dp[5005][2];
    int solve(int i,vector<int>& prices,int profit,bool bought){
        if(dp[i][bought]!=-1)return dp[i][bought];
        if(i >= prices.size())return profit;
        int ans = 0;
        if(bought)
        {   
            //sell
            ans = max(solve(i+2,prices,profit+prices[i],false),ans);
            //cooldown
            ans = max(ans,solve(i+1,prices,profit,true));
        }
        else{
            //buy
            ans = max(ans,solve(i+1,prices,profit-prices[i],true));
            //cooldown
            ans = max(ans,solve(i+1,prices,profit,false));
        }
        return dp[i][bought]=ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(0,prices,0,false);
        
    }
};