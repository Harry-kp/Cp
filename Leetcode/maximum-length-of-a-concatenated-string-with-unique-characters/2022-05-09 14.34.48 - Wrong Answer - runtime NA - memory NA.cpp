class Solution {
public:
    int maxLength(vector<string>& arr) {
        
        vector<pair<int,int>> dp(arr.size());
        
        int n = arr.size();
        for(int i = 0;i<n;i++){
            int m = 0;
            
            for(auto c:arr[i]){
                m|=(1<<(c-'a'));
            }
            dp[i] = make_pair(m,arr[i].size());
        }
        
        
        for(int i = 1;i<n;i++){
            auto tmp = dp[i];
            for(int j = i-1;j>=0;j--){
                
                if((dp[i].first&dp[j].first) == 0)
                {
                    if(dp[i].second + dp[j].second>tmp.second)
                        tmp = make_pair(dp[i].first|dp[j].first,dp[i].second + dp[j].second);
                }else if(dp[j].second>tmp.second)
                    tmp = dp[j];
                    
            }
            dp[i] = tmp;
        }
        
        return dp[n-1].second;
    }
};