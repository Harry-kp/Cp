class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> potential_k;
        vector<int> ival(n);
        ival[0] = nums[0];
        
        for(int i = 1;i<n;i++)
            ival[i] = min(ival[i-1],nums[i]);
        
        
        //search for potential j value
        
        for(int j = n-1;j>=0;j--){
            //if current jval is less than ival, continue as it will not make 132 pair
            if(nums[j]<=ival[j])
                continue;
            
            //find the smallest kval from stack which is greater than ival
            while (!potential_k.empty() and potential_k.top()<=ival[j])
                potential_k.pop();
            
            //now either we have empty stack or topmost element of stacki.e kval>ival
            
            if(!potential_k.empty() and potential_k.top()<nums[j])
                return true;
            else
                potential_k.push(nums[j]);
        }
        return false;
    }
};