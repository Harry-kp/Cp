class Solution {
public:
    int segregate(vector<int>& A){
        int n = A.size();
        int j = 0;
        for(int i = 0;i<n;i++){
            if(A[i]>0){
                swap(A[i],A[j]);
                j++;
            }
        }
        
        return j;
    }
    
    
    
    int firstMissingPositive(vector<int>& nums) {
        
        int j = segregate(nums);
        for(int i = 0;i<j;i++){
            int ind = nums[i];
            if(ind>=j or nums[ind-1]<0)continue;
            nums[ind-1]*=-1;
        }
        for(int i = 0;i<j;i++){
            if(nums[i]>0)
                return i+1;
        }
        return j+1;
    }
};