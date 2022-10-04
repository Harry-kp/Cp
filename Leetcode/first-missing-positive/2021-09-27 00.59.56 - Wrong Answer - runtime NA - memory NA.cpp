class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>0 and ans + 1 == nums[i])
                ans = nums[i];
        }
        return ans+1;
    }
};