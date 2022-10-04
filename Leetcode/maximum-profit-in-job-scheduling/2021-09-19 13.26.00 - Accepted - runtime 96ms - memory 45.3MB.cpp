class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = profit.size();
        int ref_array[n];
        for(int i = 0;i<n;i++)
            ref_array[i] = i;
        
        sort(ref_array,ref_array+n,[&](int &x,int &y){
            return endTime[x]<endTime[y];
        });
            
        int dp[n];
        dp[0] = profit[ref_array[0]];
        
        for(int i = 1;i<n;i++){
            int including = profit[ref_array[i]];
            
            int prev_non_conflict = -1;
            for(int j = i-1;j>=0;j--){
                if(endTime[ref_array[j]]<=startTime[ref_array[i]]){
                    prev_non_conflict = j;
                    break;
                }
            }
            
            if(prev_non_conflict!=-1){
                including += dp[prev_non_conflict];
                
            }
            dp[i] = max(dp[i-1],including);
        }
        return dp[n-1];
    }
};