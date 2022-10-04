class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0,buy = 10000000;
        
        for(int i = 0;i<prices.size();i++){
            if(prices[i]<=buy)
                buy = prices[i];
            else if(prices[i]<prices[i-1]){
                // cout<<buy<<" "<<prices[i-1]<<'\n';
                profit += (prices[i-1]- buy);
                buy = prices[i];
            }
        }
        // cout<<buy<<" "<<prices[prices.size()-1]<<'\n';
        if(prices[prices.size()-1]>buy)
            profit += (prices[prices.size()-1]-buy);
        return profit;
    }
};