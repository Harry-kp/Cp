class Solution {
public:
    int count(vector<int>& nums,int k){
        int c = 0;
        for(auto x:nums){
            if(x>=k)
                c++;
        }
        return c;
            
    }
    int search(vector<int>& nums){
        
        int l = -1;
        int r = nums.size()+5;
        
        while(r-l>1){
            int m = (l+r)/2;
            int c = count(nums,m);
            
            if(c == m)return m;
            else if(c<m)
                r=m;
            else
                l=m;
            
        }
        return -1;
    }
    int specialArray(vector<int>& nums) {
        return search(nums);
    }
};