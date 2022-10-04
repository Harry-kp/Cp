class Solution {
public:
    
    int dp[5005][2];
    int solve(int i,vector<int>& prices,bool buying){
        if(i>=prices.size())return 0;
        
        if(dp[i][buying]!=-1)return dp[i][buying];
        //cooldown or ignore the current day
        int ans = solve(i+1,prices,buying);
        
        if(buying){
            int amt = solve(i+1,prices,false)-prices[i];
            ans = max(ans,amt);
        }else{
            int amt = solve(i+2,prices,true)+prices[i];
            ans = max(ans,amt);
        }
        
        return dp[i][buying]=ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(0,prices,true);
        
    }
};