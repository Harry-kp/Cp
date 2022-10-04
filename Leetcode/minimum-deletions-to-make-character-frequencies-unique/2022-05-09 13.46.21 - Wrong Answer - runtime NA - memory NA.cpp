class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        
        vector<int> freq;
        for(auto k:mp)
            freq.push_back(k.second);
        sort(freq.begin(),freq.end());
        
        int res = 0;
        int max_unique = 1000000;
        
        for(auto c:freq){
            if(c>max_unique){
                res+=(c-max_unique);
                c = max_unique;
            }
                
            max_unique = max(0,c-1);
        }
        return res;
    }
};