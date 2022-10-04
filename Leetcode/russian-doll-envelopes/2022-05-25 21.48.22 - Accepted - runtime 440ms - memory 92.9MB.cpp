class Solution {
public:
   
    int maxEnvelopes(vector<vector<int>>& e) {
        
        vector<pair<int,int>> p;
        for(auto x:e){
            p.push_back({x[0],x[1]});
        }
        
        sort(p.begin(),p.end(),[](const pair<int,int>& a,const pair<int,int>& b){
            if(a.first == b.first)
                return a.second>b.second;
            return a.first<b.first;
            
        });
        vector<int> dp;
        for (auto e : p)
        {
            auto iter = lower_bound(dp.begin(), dp.end(), e.second);
            if (iter == dp.end())
                dp.push_back(e.second);
            else if (e.second < *iter)
                *iter = e.second;
        }
        return dp.size();
        
        
    }
};