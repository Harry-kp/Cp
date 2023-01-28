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
        set<int> st;
        
        for(auto x:p){
            st.insert(x.second);
            auto i = upper_bound(st.begin(),st.end(),x.second);
            if(i!=st.end())
                st.erase(i);
        }
        return st.size();
        
        
    }
};