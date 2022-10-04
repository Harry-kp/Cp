class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int tot = 0;
        for(auto a:nums){
            tot+=a;
        }
        if(tot<x)
            return -1;
        
        if(tot == x)
            return (int)nums.size();
        
        int res = tot-x;
        int n = nums.size();
        int l = 0;
        int r = 0;
        int ans = 0;
        int cur=0;
        while(r<n){
            while(r<n and cur<res){
                cur+=nums[r];
                r++;
            }
            // cout<<cur<<r<<'\n';
            while(cur>=res){
                if(cur == res){
                    ans = max(ans,r-l);
                }
                cur-=nums[l];
                l++;
            }
            // cout<<cur<<'\n';
        }
        cout<<ans<<'\n';
        return (ans==0)?-1:n-ans;
    }
};