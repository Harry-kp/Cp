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
        for(int i = freq.size()-2;i>=0;i--){
            while(freq[i] == freq[i+1])
            {
                freq[i]--;
                res++;
            }
        }
        return res;
    }
};