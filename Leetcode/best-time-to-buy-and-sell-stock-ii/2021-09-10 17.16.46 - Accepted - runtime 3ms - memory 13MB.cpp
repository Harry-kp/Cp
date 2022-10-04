class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0,buy = prices[0];
        
        for(int i = 1;i<prices.size();i++){
            if(prices[i]<=prices[i-1])
                buy = prices[i];
            else {
                // cout<<buy<<" "<<prices[i-1]<<'\n';
                profit += (prices[i]- buy);
                buy = prices[i];
            }
        }
        // cout<<buy<<" "<<prices[prices.size()-1]<<'\n';
        if(prices[prices.size()-1]>buy)
            profit += (prices[prices.size()-1]-buy);
        return profit;
    }
};