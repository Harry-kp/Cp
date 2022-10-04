class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int a = 0;
        int b=n;
        for(int i = 0;i<n;i++){
            a^=nums[i];
            b^=i;
        }
        return a^b;
    }
};