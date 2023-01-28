class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int place = 1;

        for(int i = 1;i<nums.size();i++){
            if(nums[place-1]!=nums[i]){
                nums[place] = nums[i];
                place++;
            }
        }
        return place;
    }
};