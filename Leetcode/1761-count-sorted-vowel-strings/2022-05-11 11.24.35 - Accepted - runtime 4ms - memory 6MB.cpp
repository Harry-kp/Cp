class Solution {
public:
    int dp[51][26];
    char a[5] = {'a','e','i','o','u'};
    int solve(int n,char prev){
        if(n == 0)return 1;
        
        if(dp[n][prev-'a']!=-1)return dp[n][prev-'a'];
        int ans = 0;
        for(int i = 0;i<5;i++){
            if(a[i]>=prev)
                ans+=solve(n-1,a[i]);
        }
        return dp[n][prev-'a']=ans;
    }
    int countVowelStrings(int n) {
        memset(dp,-1,sizeof dp);
        return solve(n,'a');
    }
};