class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0;
        int h = nums.size()-1;
        
        while(nums[l]%2==0)l++;
        while(nums[h]%2==1)h--;
        
        while(l<h){
            swap(nums[l],nums[h]);
            while(nums[l]%2==0)l++;
            while(nums[h]%2==1)h--;
            
        }
            
         return nums;  
    }
};