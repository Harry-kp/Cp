class Solution {
public:
    int dp[5*10005][2];
    int solve(int i,vector<int>& prices,bool buying,int& fee){
        if(i>=prices.size())return 0;
        
        if(dp[i][buying]!=-1)return dp[i][buying];
        
        int ans = solve(i+1,prices,buying,fee);
        if(buying){
            int amt = solve(i+1,prices,false,fee)-prices[i];
            ans = max(ans,amt);
        }else{
            int amt = solve(i+1,prices,true,fee)+prices[i]-fee;
            ans = max(ans,amt);
        }
        return dp[i][buying]=ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof dp);
        return solve(0,prices,true,fee);
        
    }
};