class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0;
        int h = nums.size()-1;
        while(l<nums.size() and nums[l]%2==0)l++;
        while(h>=0 and nums[h]%2==1)h--;
        
        while(l<h){
            swap(nums[l],nums[h]);
            while(nums[l]%2==0)l++;
            while(nums[h]%2==1)h--;
            
        }
            
         return nums;  
    }
};