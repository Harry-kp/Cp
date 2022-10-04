class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int ans = 1,n = nums.size();
        for(int j = 0;j<60;j++)
        for(int i = 0;i<n;i++){
            if(nums[i]>0 and nums[i] == ans)
                ans++;
        }
        return ans;
    }
};