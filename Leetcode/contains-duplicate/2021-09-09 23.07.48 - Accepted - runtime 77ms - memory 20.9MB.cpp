class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> m1;
        for(auto x:nums){
            if(m1.find(x) !=m1.end())
                return true;
            m1.insert(x);
        }
        return false;
    }
};