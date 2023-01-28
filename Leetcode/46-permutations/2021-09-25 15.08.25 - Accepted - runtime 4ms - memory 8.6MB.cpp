class Solution {
public:
    
    vector<vector<int>> ans;
    int full;
    int n;
    void solve(int mask,vector<int> per,vector<int>& nums){
        if(mask == full){
            ans.emplace_back(per);
            return ;
        }
        
        for(int i = 0;i<n;i++){
            if((mask&(1<<i)) == 0){
                per.push_back(nums[i]);
                solve(mask|(1<<i),per,nums);
                per.pop_back();
            }
                
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        full = (1<<n)-1;
        solve(0,{},nums);
        
        return ans;
    }
};