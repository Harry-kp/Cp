class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i = k,prev = nums[0];
        int lop = nums.size();
        while(lop--){
            swap(nums[i],prev);
            i = (i+k)%nums.size();
        }
    }
};