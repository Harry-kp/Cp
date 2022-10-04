class Solution {
public:
    int bound(const vector<int>& nums){
        stack<int> st;
        int b = nums.size()-1;
        
        for(int i = 0;i<nums.size()-1;i++){
            while(!st.empty() and nums[st.top()]>nums[i]){
                b = min(b,st.top());
                st.pop();
            }
            st.push(i);
        }
        
        return b;
    }
    
    int findUnsortedSubarray(vector<int>& nums) {
        //using stack
        
        int l = bound(nums);
        reverse(nums.begin(),nums.end());
        int r = nums.size()-bound(nums)-1;
        
        return (l==r)?0:r-l;
        
        
    }
};