class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0;
        int n = nums1.size();
        vector<int> tmp1,tmp2;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
            {
                tmp1.push_back(nums1[i] + nums2[j]);
                tmp2.push_back(nums3[i] + nums4[j]);
            }
        
        sort(tmp1.begin(),tmp1.end());
        
        for(auto x:tmp2){
            ans += (upper_bound(tmp1.begin(),tmp1.end(),-x) - lower_bound(tmp1.begin(),tmp1.end(),-x));
        }
        return ans;
    }
};