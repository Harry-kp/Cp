class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int min1 = INT_MAX;
        int max1 = INT_MIN;
        
        int min_ind = -1;
        int max_ind = -1;
        
        for(int i = 0;i<n;i++){
            
            //check max 
            if(nums[i]<=min1){
                min_ind = i;
                min1 = nums[i];
            }
            
            if(nums[i]>max1){
                max_ind = i;
                max1 = nums[i];
            }
            
            if(max_ind-min_ind>0)
                return true;
            
            
            
        }
        return false;
    }
};