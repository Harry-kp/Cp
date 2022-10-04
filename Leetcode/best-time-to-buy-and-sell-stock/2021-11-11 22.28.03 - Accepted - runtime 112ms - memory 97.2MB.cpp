class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> diff(prices.size());
        
        int n = prices.size();
        for(int i = 1;i<n;i++){
            diff[i] = prices[i]-prices[i-1];
        }
        
        int ans = 0,tmp = 0;
        for(int i = 0;i<n;i++){
            tmp+=diff[i];
            ans = max(ans,tmp);
            tmp = max(0,tmp);
        }
        return ans;
    }
};