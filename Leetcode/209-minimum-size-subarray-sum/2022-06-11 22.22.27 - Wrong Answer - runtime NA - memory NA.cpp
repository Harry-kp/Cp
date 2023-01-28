class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(),l=0,r=0,cur=0,ans=nums.size();
        
        while(r<n){
            while(r<n and cur<target)
            {
                cur+=nums[r];
                r++;
            }
            
            while(cur>=target){
                ans = min(ans,r-l);
                cur-=nums[l];
                l++;
            }
            
        }
        return ans == n?0:ans;
    }
};