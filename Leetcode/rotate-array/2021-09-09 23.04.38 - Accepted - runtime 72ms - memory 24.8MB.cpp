class Solution {
public:
    void reverse(vector<int> &nums,int l,int r){
        int i,j;
        for(i = l,j = r;i<j;i++,j--){
            swap(nums[i],nums[j]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;  //without this problem may arise as n-k<0
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-k-1);
        reverse(nums,0,n-1);
}
};