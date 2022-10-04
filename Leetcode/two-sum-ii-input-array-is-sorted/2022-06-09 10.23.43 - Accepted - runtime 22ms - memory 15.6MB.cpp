class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        int l = 0;
        int r = n.size()-1;
        
        while(l<r){
            if(n[l]+n[r] == t)
                return {l+1,r+1};
            else if(n[l]+n[r]<t)
                l++;
            else
                r--;
        }
        return {1,2};
    }
};