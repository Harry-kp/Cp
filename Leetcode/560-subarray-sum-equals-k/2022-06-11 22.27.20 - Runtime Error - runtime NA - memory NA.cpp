class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(),l=0,r=0,cur=0,ans=0;
        
        while(r<n){
            while(r<n and cur<k)
            {
                cur+=nums[r];
                r++;
            }
            
            while(cur>=k){
                if(cur == k)
                    ans++;
                cur-=nums[l];
                l++;
            }
            
        }
        return ans;
    }
};