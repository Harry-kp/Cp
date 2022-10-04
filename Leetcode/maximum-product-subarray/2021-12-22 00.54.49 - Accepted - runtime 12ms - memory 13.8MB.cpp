class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int plus,minus,ans;
        plus = nums[0];
        minus = nums[0];
        ans = nums[0];
        
        for(int i = 1;i<nums.size();i++){
            int tmp = max({nums[i],plus*nums[i],minus*nums[i]});
            minus = min({nums[i],plus*nums[i],minus*nums[i]});
            plus = tmp;
            ans = max(ans,plus);
        }
        return ans;
    }
};