class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        
        for(auto x:nums){
            st.insert(x);
        }
        int res = 0;
        for(auto x:nums){
            if(st.find(x-1) == st.end()){
                int cur = x;
                int streak = 1;
                
                while(st.find(cur+1)!=st.end()){
                    cur++;
                    streak++;
                }
                res = max(res,streak);
            }
            
        }
        return res;
    }
};