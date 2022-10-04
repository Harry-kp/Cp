class Solution {
public:
    
    int findUnsortedSubarray(vector<int>& nums) {
        //using stack
        
        stack<int> s;
        int l = nums.size()-1;
        
        for(int i = 0;i<nums.size();i++){
            while(!s.empty() and nums[s.top()]>nums[i])
            {
                l = min(l,s.top());
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())s.pop();
        int r = 0;
        for(int i = nums.size()-1;i>=0;i--){
            while(!s.empty() and nums[s.top()]<nums[i])
            {
                r = max(r,s.top());
                s.pop();
            }
            s.push(i);
        }
        return (r==l)?0:r-l+1;
        
        
    }
};