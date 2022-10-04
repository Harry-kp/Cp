class Solution {
public:
    void reverse(vector<int> &nums,int l,int r){
        if(l<0)return;
        int i,j;
        for(i = l,j = r;i<j;i++,j--){
            swap(nums[i],nums[j]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-k-1);
        reverse(nums,0,n-1);
}
};