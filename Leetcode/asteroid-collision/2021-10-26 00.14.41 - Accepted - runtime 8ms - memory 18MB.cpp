class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteriods) {
        
        int n = asteriods.size();
        vector<int> mask(n,1);
        
        vector<int> ans;
        
        stack<int> st;
        
        for(int i = 0;i<n;i++){
            
            if(asteriods[i]>0)
                st.push(i);
            else{
                int val = abs(asteriods[i]);
                while(!st.empty() and asteriods[st.top()]<val){
                    mask[st.top()] = 0;
                    st.pop();
                }
                
                if(st.empty())continue;
                
                if(val == asteriods[st.top()]){
                    mask[i] = 0;
                    mask[st.top()] = 0;
                    st.pop();
                }else{
                    mask[i] = 0;
                }
                
                
            }
        }
        
        for(int i = 0;i<n;i++){
            if(mask[i])
                ans.push_back(asteriods[i]);
        }
        
        return ans;
    }
};