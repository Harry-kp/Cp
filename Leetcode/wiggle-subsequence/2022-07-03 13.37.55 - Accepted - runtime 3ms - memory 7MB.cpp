class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2)return nums.size();
        
        int prev = nums[1]-nums[0];
        int c = prev == 0?1:2;
        
        for(int i = 2;i<nums.size();i++){
            if((nums[i]-nums[i-1]>0 and prev<=0) or (nums[i]-nums[i-1]<0 and prev>=0))
            {
                c++;
                prev = nums[i]-nums[i-1];
            }
        }
        return c;
    }
};