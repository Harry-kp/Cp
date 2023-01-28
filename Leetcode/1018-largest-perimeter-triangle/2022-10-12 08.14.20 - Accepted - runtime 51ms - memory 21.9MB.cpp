class Solution {
public:
    bool good(int a, int b, int c){
        return (a+b>c and b+c>a and c+a>b);
    }
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        
        for(int i = 0;i<nums.size()-2;i++)
        {
            if(good(nums[i],nums[i+1],nums[i+2]))
                return nums[i]+nums[i+1]+nums[i+2];
        }
        return 0;
    }
};