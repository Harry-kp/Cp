class Solution {
public:
    
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<5)
            return 0;
        int ans = 2*100000000;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<4;i++){
            ans = min(ans,nums[n-4+i]-nums[i]);
        }
        return ans;
    }
};