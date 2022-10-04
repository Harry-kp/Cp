class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = cost[0];
        int b = cost[1];
        
        int n = cost.size();
        if(n<=2)
            return min(a,b);
        
        for(int i=2;i<n;i++){
            int c = cost[i]+min(a,b);
            a = b;
            b=c;
        }
        return min(a,b);
    }
};