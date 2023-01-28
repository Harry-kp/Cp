class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // a double ended queue which at any instance stores elements in descending order from front to back    
        int n = nums.size();
        deque<int> dq(k);
        
        int i = 0;
        for(;i<k;i++){
            while(!dq.empty() and nums[i]>=nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        vector<int> ans;
        
        for(;i<n;i++){
            ans.push_back(nums[dq.front()]);
            //remove redundant elements
            while(!dq.empty() and dq.front()<=i-k)
                dq.pop_front();
            
            //push next element
            while(!dq.empty() and nums[i]>=nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};