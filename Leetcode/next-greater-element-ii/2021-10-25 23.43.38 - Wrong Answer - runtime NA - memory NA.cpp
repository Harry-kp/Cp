class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        
        int mx = 1e9+5;
        int ind = -1;
        
        for(int i = 0;i<n;i++){
            if(mx>=nums[i]){
                mx = nums[i];
                ind = i;
            }
        }
        
        stack<int> st;
        st.push((ind)%n);
        
        int i = (ind+1)%n;
        while(i!=ind){
            
            while(!st.empty() and nums[st.top()]<nums[i]){
                ans[st.top()] = nums[i];
                st.pop();
            }
            
            st.push(i);
            i = (i+1)%n;
        }
        return ans;
        
    }
};