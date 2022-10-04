class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[prev]!=nums[i]){
                prev++;
                nums[prev] = nums[i];
            }
        }
        return (nums.size() == 0)?0:prev+1;
    }
};