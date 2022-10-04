class Solution {
public:
    int solve(int l,int r,vector<int>& nums){
        if(l>=nums.size() or r<0 or r<l)return 0;
        if(r==l)return nums[l];
        int x = solve(l+2,r,nums);
        int y = solve(l+1,r-1,nums);
        int z = solve(l,r-2,nums);
        
        return max(nums[l] + min(x,y),nums[r] + min(y,z));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum1 = 0;
        for(auto x:nums)sum1+=x;
        return 2*solve(0,nums.size()-1,nums)>=sum1;
    }
};