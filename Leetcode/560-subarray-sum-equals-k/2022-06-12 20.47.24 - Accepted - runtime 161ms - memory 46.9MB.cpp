class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         unordered_map<int,int>  mp;
        
        int n = nums.size();
        int cur=0,ans=0;
        
        for(int i = 0;i<n;i++){
            cur+=nums[i];
            
            if(mp[cur-k])ans+=mp[cur-k];
            if(cur == k)ans++;
            
            mp[cur]++;
        }
        return ans;
    }
};