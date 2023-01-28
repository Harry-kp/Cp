class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_multiset<int> mp;
        
        int ans = 0;
        for(auto x:nums){
            if(mp.count(k-x)){
                ans++;
                mp.erase(mp.find(k-x));
                cout<<x<<" "<<k-x<<'\n';
            }else{
                mp.insert(x);
            }
        }
        return ans;
    }
};