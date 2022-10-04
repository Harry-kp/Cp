class Solution {
public:
    vector<vector<int>> ans;
        
    void solve(vector<int>& nums,int mask,vector<int> p1){
        if(p1.size() == nums.size()){
            ans.push_back(p1);
            return ;
        }
        unordered_set<int> st;
        for(int i = 0;i<nums.size();i++){
            
            if(!(mask&(1<<i)) and !st.count(nums[i])){
                p1.push_back(nums[i]);
                st.insert(nums[i]);
                solve(nums,mask|(1<<i),p1);
                p1.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums,0,{});
        return ans;
    }
};