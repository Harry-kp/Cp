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
        int ans = n;
        int cur=0;
        while(r<n){
            while(r<n and cur<res){
                cur+=nums[r];
                r++;
            }
            
            while(cur>=res){
                if(cur == res){
                    ans = min(ans,r-l+1);
                }
                cur-=nums[l];
                l++;
            }
        }
        return (ans==n)?-1:n-ans;
    }
};