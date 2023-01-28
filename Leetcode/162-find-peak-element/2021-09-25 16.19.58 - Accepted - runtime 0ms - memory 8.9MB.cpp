class Solution {
public:
    int solve(vector<int> &nums,int l,int r){
        if(l == r){
            if(l-1<0)
                return (nums[l]>nums[l+1])?l:-1;
            if(r+1>=nums.size())
                return (nums[r]>nums[r-1])?r:-1;
            return (nums[l]>nums[l+1] and nums[l]>nums[l-1])?l:-1;
            
        }
        
        int m = (l+r)/2;
        int lans = solve(nums,l,m);
        int rans = solve(nums,m+1,r);
        
        if(lans!=-1)return lans;
        if(rans!=-1)return rans;
        return -1;
        
    }
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)return 0;
        return solve(nums,0,nums.size()-1);
    }
};