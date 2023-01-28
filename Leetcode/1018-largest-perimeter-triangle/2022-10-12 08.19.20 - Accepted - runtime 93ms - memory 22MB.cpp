class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        
        for(int i = 0;i<nums.size()-2;i++)
        {
            if(nums[i+2]+nums[i+1]>nums[i])
                return nums[i]+nums[i+1]+nums[i+2];
        }
        return 0;
    }
};