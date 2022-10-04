class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        
        int c = 0;
        for(int i = 1;i<n;i++){
            if(nums[i]<nums[i-1]){
                c++;
                
                if(i<2 or nums[i-2]<=nums[i])
                    nums[i-1]=nums[i];
                else
                    nums[i]=nums[i-1];
            }
        }
        return c<=1;
    }
};