class Solution {
public:
    
    int findUnsortedSubarray(vector<int>& nums) {
        //using O(1)
        
        //first compress...find the sorted array from left and right
        
        int l1 = 0,r1 = nums.size()-1;
        
        while(l1+1<nums.size() and nums[l1]<=nums[l1+1])l1++;
        while(r1-1>=0 and nums[r1]>=nums[r1-1])r1--;
        
        
        //find max and min value in unsorted array [l1...r1]
        
        int max1 = -1000000,min1 = 1000000;
        for(int i = l1;i<=r1;i++){
            max1 = max(nums[i],max1);
            min1 = min(nums[i],min1);
        }
        
        //decompress the arr[l1...r1],upto the original place of max1 and min1
        // cout<<l1<<" "<<r1<<'\n';
        int l = 0;
        int r = nums.size()-1;
        
        while(l<l1 and min1>nums[l])
            l++;
        while(r>r1 and max1<nums[r])
            r--;
        
        return (r<=l)?0:r-l+1;
        
        
    }
};