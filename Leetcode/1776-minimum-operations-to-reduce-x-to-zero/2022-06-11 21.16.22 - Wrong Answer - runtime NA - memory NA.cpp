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
        
        int l = 0;
        int r = 0;
        
        int n = nums.size();
        int ans = n;
        int cur=0;
        while(r<n){
            cur+=nums[r];
            
            if(cur >= res){
                if(cur==res)
                    ans = min(ans,r-l+1);
                cur = 0;
                l=r;
            }
            r++;
        }
        return (ans == n)?-1:n-ans;
    }
};