class Solution {
public:
    int dp[999][2][105];
    int solve(int i,vector<int>& prices,bool buying,int t){
        if(i>=prices.size() or t<=0)return 0;
        
        if(dp[i][buying][t]!=-1)return dp[i][buying][t];
        
        int ans = solve(i+1,prices,buying,t);
        if(buying){
            int amt = solve(i+1,prices,false,t)-prices[i];
            ans = max(ans,amt);
        }else{
            int amt = solve(i+1,prices,true,t-1)+prices[i];
            ans = max(ans,amt);
        }
        return dp[i][buying][t]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return solve(0,prices,true,k);
    }
};