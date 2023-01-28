class Solution {
public:
    int solve(int l,int r,vector<int>& nums){
        if(r==l)return nums[l];
        return max(nums[l]-solve(l+1,r,nums),nums[r]-solve(l,r-1,nums));
    }
    bool PredictTheWinner(vector<int>& nums) {
        return solve(0,nums.size()-1,nums)>=0;
    }
};