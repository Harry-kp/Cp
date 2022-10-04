class Solution {
public:
    
    vector<int> searchRange(vector<int>& nums, int target) {
        auto l = lower_bound(nums.begin(),nums.end(),target);
        auto u = upper_bound(nums.begin(),nums.end(),target);
        
        if(l == nums.end() || *l != target)    return {-1,-1};
        
        int a = l - nums.begin();
        int b = u - nums.begin()-1;
        return {a,b};
    }
};