class Solution {
public:
    int binary(int l,int r,vector<int>& nums,int key){
        if(l>r)return -1;
        
        int mid = (l+r)/2;
        
        if(nums[mid] == key)return mid;
        
        //if left side is sorted
        if(nums[l]<=nums[mid]){
            if(key<=nums[mid] and key>=nums[l])
                return binary(l,mid-1,nums,key);
            return binary(mid+1,r,nums,key);
            
        //else right half is obviously sorted
        }else{
            if(key>=nums[mid] and key<=nums[r])
                return binary(mid+1,r,nums,key);
            return binary(l,mid-1,nums,key);
        }
    }
    int search(vector<int>& nums, int target) {
        return binary(0,nums.size()-1,nums,target);
    }
};