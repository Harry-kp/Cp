class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 2)
            return max(nums[0],nums[1]);
        for(int i = 2;i<nums.size();i++){
            nums[i] = max(nums[i-1],nums[i]+nums[i-2]);
        }
        return nums[nums.size()-1];

    }
    
};