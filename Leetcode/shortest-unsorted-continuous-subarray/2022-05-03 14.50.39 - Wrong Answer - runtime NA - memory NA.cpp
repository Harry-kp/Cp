class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()==1)return 0;
        vector<int> a(nums.begin(),nums.end());
        
        sort(a.begin(),a.end());
        
        int l = 0;
        int r = nums.size()-1;
        
        while(l<r){
            if(nums[l] != a[l] and nums[r]!=a[r])
                break;
            
            if(nums[l]==a[l])l++;
            if(nums[r]==a[r])r--;
        }
        return (r-l+1);
    }
};