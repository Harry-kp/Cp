class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        
        while(l<=r){
            
            int m = (l+r)>>1;
            // cout<<l<<" "<<m<<" "<<r<<'\n';
            if(nums[m] == target)return m;
            
            //left portion sorted
            if(nums[l]<=nums[m]){
                if(target>=nums[l] && target<nums[m]){
                    r=m-1;
                }else
                    l=m+1;
            }else{
                if(target<=nums[r] && target>nums[m]){
                    l=m+1;
                }else
                    r=m-1;
            }
            
        }
        return -1;
        
    }
};