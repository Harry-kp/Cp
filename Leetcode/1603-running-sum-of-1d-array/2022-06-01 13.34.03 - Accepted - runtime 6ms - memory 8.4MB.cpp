class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res(nums.size());
        partial_sum(nums.begin(),nums.end(),res.begin());
        return res;
    }
};