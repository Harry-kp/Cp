class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        
        vector<int> dp(t.back());
        
        for(int r = n-2;r>=0;r--){
            for(int c = 0;c<=r;c++)
                dp[c] = t[r][c] + min(dp[c],dp[c+1]);
        }
        return dp[0];
    }
};