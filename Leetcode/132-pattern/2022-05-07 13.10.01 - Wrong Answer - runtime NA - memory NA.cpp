class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n),b(n);
        
        a[0] = nums[0];
        for(int i = 1;i<n;i++){
            a[i] = min(a[i-1],nums[i]);
        }
        
        b[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            b[i] = min(b[i+1],nums[i]);
        }
        
        for(int i = 0;i<n;i++){
            if(a[i]<nums[i] and nums[i]>b[i])
                return true;
        }
        return false;
    }
};