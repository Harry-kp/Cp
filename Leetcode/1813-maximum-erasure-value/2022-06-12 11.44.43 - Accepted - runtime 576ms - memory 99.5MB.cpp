class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> m1;
        
        int ans = 0,l = 0,r = 0,n = nums.size(),cur=0;
        
        while(r<n){
            
            cur+=nums[r];
            if(m1.find(nums[r]) != m1.end() and m1[nums[r]]>=l){
                // cout<<"ss "<<cur<<'\n';
                auto tmp = *m1.find(nums[r]);
                // cout<<tmp.first<<" "<<tmp.second<<'\n';
               int m = m1[nums[r]];
                while(l<=m){
                    cur-=nums[l];
                    l++;
                }
            }
            // cout<<cur<<'\n';
            ans = max(ans,cur);
            m1[nums[r]] = r;
                r++;
        }
        return ans;
    }
};