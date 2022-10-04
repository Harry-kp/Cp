class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        bool dp[n][n];
        int c = 0;
        for(int j = 0;j<2;j++)
        for(int i = 0;i<n-j;i++){
            if(s[i] == s[i+j]){
                dp[i][i+j] = true;
                c++;
            }else
                dp[i][i+j] = false;
        }
        
        for(int j = 2;j<n;j++)
        for(int i = 0;i<n-j;i++){
                dp[i][i+j] = (s[i] == s[i+j])&dp[i+1][i+j-1];
                c+=dp[i][i+j];
                
        }
        
        return c;
    }
};