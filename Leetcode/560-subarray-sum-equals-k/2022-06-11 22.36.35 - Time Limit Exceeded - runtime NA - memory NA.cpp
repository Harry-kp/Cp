class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(),l=0,r=0,cur=0,ans=0;
        bool start=false;
        while(r<n){
            while(r<n and cur<k)
            {
                start=true;
                cur+=nums[r];
                r++;
            }
            
            while(l<r and cur>=k){
                if(start and cur == k)
                    ans++;
                cur-=nums[l];
                l++;
            }
            
        }
        return ans;
    }
};