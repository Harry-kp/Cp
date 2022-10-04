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
        // for(auto x:p){
        //     cout<<x.first<<" "<<x.second<<'\n';
        // }
        set<pair<int,int>> st;
        
        for(auto x:p){
            st.insert(x);
            
            auto i = upper_bound(st.begin(),st.end(),x);
            if(i!=st.end())st.erase(i);
        }
        // for(auto x:st){
        //     cout<<x.first<<" "<<x.second<<'\n';
        // }
        return st.size();
        
        
        
        
        
    }
};