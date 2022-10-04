class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)return 0;
        int n = nums.size(),l=0,ans=0,cur=1;
        
        for(int i = 0;i<n;i++){
            cur*=nums[i];
            
            while(cur>=k){
                cur/=nums[l];
                l++;
            }
            ans+=i-l+1;
        }
        return ans;
        
    }
};