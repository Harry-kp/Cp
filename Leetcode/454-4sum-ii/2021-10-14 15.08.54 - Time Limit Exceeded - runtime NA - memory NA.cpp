class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        sort(nums4.begin(),nums4.end());
        int ans = 0;
        for(int i = 0;i<nums1.size();i++)
            for(int j = 0;j<nums2.size();j++)
                for(int k = 0;k<nums3.size();k++){
                    int s = nums1[i] + nums2[j] + nums3[k];
                    ans += upper_bound(nums4.begin(),nums4.end(),-s) - lower_bound(nums4.begin(),nums4.end(),-s);    
                }
        return ans;
    }
};