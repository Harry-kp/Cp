class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int ans = 1,n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i]>0 and nums[i] == ans)
                ans++;
        }
        for(int i = n-1;i>=0;i--){
            if(nums[i]>0 and nums[i] == ans)
                ans++;
        }
        return ans;
    }
};