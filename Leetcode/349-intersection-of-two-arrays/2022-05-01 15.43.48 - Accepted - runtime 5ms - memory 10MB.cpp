class Solution {
public:
    bool search(const vector<int>& l1,int k){
        int l = -1;
        int r = l1.size();
        
        while(r-l>1){
            int m = (l+r)/2;
            if(l1[m]>=k)
                r=m;
            else
                l=m;
            
        }
        return (r==l1.size())?false:(l1[r]==k);
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        vector<int> ans;
        
        for(auto x:nums1){
            if(!search(ans,x) and search(nums2,x))
                ans.push_back(x);                
        }
        return ans;
    }
};