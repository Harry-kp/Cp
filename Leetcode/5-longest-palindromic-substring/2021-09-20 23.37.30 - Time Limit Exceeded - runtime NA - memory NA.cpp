class Solution {
public:
    int dp[1005][1005];
    
    bool solve(int l,int r,string s){
        if(dp[l][r]!=-1)return dp[l][r];
        if(l >= r)
            return true;
        bool ans;
        if(s[l] == s[r])
            ans = solve(l+1,r-1,s);
        else
            ans =  false;
        return dp[l][r] = ans;
    }
    
    
    string longestPalindrome(string s) {
        memset(dp,-1,sizeof dp);
        
        int l,n = s.size();
        int max1 = -1;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                if(solve(i,j,s) and max1<(j-i+1)){
                        l = i;
                        max1 = j-i + 1;
                }
            }
        }
        cout<<max1<<" "<<l<<'\n';
        return s.substr(l,max1);
    }
};