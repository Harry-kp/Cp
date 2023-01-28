class Solution {
public:
    int solve(int i,vector<int>& nums, const int& k){
        if(i == nums.size())
            return 0;
        int ans = 0;
        for(int j = 1;j<=k;j++){
            if(i+j<=nums.size())
                ans = max(ans,nums[i] + solve(i+j,nums,k));
        }
        return ans;
    }
    int maxResult(vector<int>& nums, int k) {
        return solve(0,nums,k);
    }
};