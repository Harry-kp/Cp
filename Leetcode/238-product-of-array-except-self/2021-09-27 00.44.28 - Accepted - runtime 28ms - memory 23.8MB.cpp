class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> out(n,1);
        
        int prev = 1;
        for(int i = 0;i<n;i++){
            out[i]*=prev;
            prev*=nums[i];
        }
         prev = 1;
        for(int i = n-1;i>=0;i--){
            out[i]*=prev;
            prev*=nums[i];
        }
        return out;
    }
};