
class Solution {
public:
    
    string longestPalindrome(string s) {
        bool dp[1005][1005];
        int n = s.size();
        int l = 0,ans = 1;
        
        //1 and 2 size subastring
        for(int i = 0;i<n;i++){
            dp[i][i] = true;
            
            if(i+1<n)
                if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                ans = 2;
                l = i;
            }else
                dp[i][i+1] = false;
        }
        
        //ith size substring
        
        for(int k = 3;k<=n;k++){
            for(int i = 0;i<n-k+1;i++){
                int j = i+k-1;
                
                if(s[i] == s[j] and dp[i+1][j-1]){
                    dp[i][j] = true;
                    if(ans<k){
                        ans = k;
                        l = i;
                    }
                }else
                    dp[i][j] = false;
            }
        }
        
        return s.substr(l,ans);
    }
};