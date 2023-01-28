class Solution {
public:
    int dp[12][12][2];
    int solve(int pos,int tight,int cur,string& digit){
        if(pos == digit.size())
            return cur;
        
        if(dp[pos][cur][tight]!=-1)return dp[pos][cur][tight];
        int ans = 0;
        int ub = tight?digit[pos]-'0':9;
        for(int j = 0;j<=ub;j++)
            ans+=(solve(pos+1,tight&(j==ub),cur+(j==1),digit));
        
        return dp[pos][cur][tight] = ans;
        
    }
                  
    int countDigitOne(int n) {
        for(int i = 0;i<12;i++)
            for(int j = 0;j<12;j++)
                dp[i][j][1] = dp[i][j][0] = -1;
        string digit = "";
        while(n){
            digit+=char('0'+n%10);
            n/=10;
        }
        reverse(digit.begin(),digit.end());
        
        return solve(0,1,0,digit);
    }
};