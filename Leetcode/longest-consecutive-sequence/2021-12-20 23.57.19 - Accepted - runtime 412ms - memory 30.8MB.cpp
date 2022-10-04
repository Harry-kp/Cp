class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s1;
        
        for(int i = 0;i<nums.size();i++){
            s1.insert(nums[i]);
        }
        
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            
            if(s1.find(nums[i]-1)==s1.end()){
                int j = nums[i];
                while(s1.find(j)!=s1.end())
                    j++;
                ans = max(ans,j-nums[i]);
            }
        }
        return ans;
    }
};