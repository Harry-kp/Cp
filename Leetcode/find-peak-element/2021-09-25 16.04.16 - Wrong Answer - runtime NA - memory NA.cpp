class Solution {
public:
    int solve(vector<int> &nums,int l,int r){
        if(l == r){
            int lval = (l-1<0)?-INT_MAX:nums[l-1];
            int rval = (r+1>=nums.size())?-INT_MAX:nums[r+1];
            
            return (lval<nums[l] and nums[l]>rval)?l:-1;
        }
        
        int m = (l+r)/2;
        int lans = solve(nums,l,m);
        int rans = solve(nums,m+1,r);
        
        if(lans!=-1)return lans;
        if(rans!=-1)return rans;
        return -1;
        
    }
    int findPeakElement(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};