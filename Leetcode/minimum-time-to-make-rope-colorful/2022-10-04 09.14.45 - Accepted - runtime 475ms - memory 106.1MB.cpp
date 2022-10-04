class Solution {
public:
    
    int minCost(string c, vector<int>& T) {
        stack<pair<char,int>> st;
        int ans = 0;
        int n = c.size();
        for(int i = 0;i<n;i++){
            if(st.empty() || st.top().first != c[i]){
                st.push({c[i],T[i]});
            }else
            {
                ans+=min(st.top().second,T[i]);
                int tmp = max(T[i],st.top().second);
                st.push(make_pair(c[i],tmp));
                
            }
        }
        return ans;
    }
};