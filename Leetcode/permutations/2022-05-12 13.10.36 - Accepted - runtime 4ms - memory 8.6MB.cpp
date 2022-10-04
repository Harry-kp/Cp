class Solution {
public:
    vector<vector<int>> ans;
        
    void solve(vector<int>& nums,int mask,vector<int> p1){
        if(p1.size() == nums.size()){
            ans.push_back(p1);
            return ;
        }
        
        for(int i = 0;i<nums.size();i++){
            
            if(!(mask&(1<<i))){
                p1.push_back(nums[i]);
                solve(nums,mask|(1<<i),p1);
                p1.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums,0,{});
        return ans;
    }
};