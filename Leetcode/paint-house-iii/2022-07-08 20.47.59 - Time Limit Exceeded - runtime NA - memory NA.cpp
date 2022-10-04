class Solution {
public:
    int nbr(const vector<int>& h){
        int c = 0;
        for(int i = 1;i<h.size();i++){
            if(h[i]!=h[i-1])
                c++;
        }
        return c+1;
    }
    
    int solve(vector<int> h,const vector<vector<int>>& cost,const int& m, const int& n,const int &t){
        if(find(h.begin(),h.end(),0) == h.end()){
            return nbr(h) == t?0:100000000;
        }
        int c = 100000000;
        for(int i = 0;i<m;i++){
            if(h[i] == 0){
                for(int j = 0;j<n;j++){
                    h[i] = j+1;
                    c = min(c,cost[i][j]+solve(h,cost,m,n,t));
                    h[i] = 0;
                }
            }
        }
        return c;
}
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        int res = solve(houses,cost,m,n,target);
        return res == 100000000?-1:res;
    }
};