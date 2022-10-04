class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int m = nums.size()/2;
        
        int c1 = 0;
        
        for(auto x:nums)
            c1+=abs(x-nums[m]);
        
        if(nums.size()%2==0)
        {
            int c2 = 0;
            
            m--;
            for(auto x:nums)
                c2+=abs(x-nums[m]);
            return min(c1,c2);
        }
        return c1;
        
    }
};