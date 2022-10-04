class Solution {
public:
    bool canJump(vector<int>& nums) {
        int fat = 0,n = nums.size();
        if(n==1)return true;
        for(int i = 0;i<n;i++){
            if(nums[i] == 0 and fat == i)return false;
            fat = max(fat,nums[i]+i);
            if(fat>=n-1)return true;
        }
        return false;
    }
};