class Solution {
public:
    vector<vector<int>> ans;
        
    void solve(int i,vector<int>& nums){
        if(i == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> st;
        
        for(int j = i;j<nums.size();j++){
            if(!st.count(nums[j])){
                st.insert(nums[j]);
                swap(nums[j],nums[i]);
                solve(i+1,nums);
                swap(nums[j],nums[i]);
            }
        }
    }
        
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(0,nums);
        return ans;
    }
};