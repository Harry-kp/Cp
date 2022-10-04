class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        int first = nums[0];
        int second = INT_MAX;
        
        for(int i = 1;i<n;i++){
            if(nums[i]>second)return true;
            
            if(first<nums[i]){
                second = min(second,nums[i]);
            }else{
                
                first = nums[i];
            }
        }
        return false;
    }
};