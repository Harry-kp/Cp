class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        int n = 0;
        for(auto k:edges){
            n = max(n,k[0]);
            n = max(n,k[1]);
            mp[k[0]]++;
            mp[k[1]]++;
        }
        
        for(auto &[x,y]:mp){
            if(y == n-1)return x;
        }
        return 0;
    }
};