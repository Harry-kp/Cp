class Solution {
public:
    int dp[1005][2];
    
    //TURN
    //ALICE = 0
    //BOB = 1
    bool solve(int i,int turn){
        if(i == 1 or i == 3)return false;
        if(i==2)return true;
        
        if(dp[i][turn]!=-1)return dp[i][turn];
        int ans = (turn == 0)?0:1;
        
        for(int j = 1;j*j<=i;j++){
            if(i%j == 0){
                //if alice turn
                if(turn == 0)
                    ans|=solve(i-j,1);
                else
                    ans&=solve(i-j,0);
            }
        }
        return dp[i][turn]=ans;
        
    }
    bool divisorGame(int n) {
        memset(dp,-1,sizeof dp);
        return solve(n,0);
    }
};