class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        
        for(auto c:s)mp[c]++;
        
        vector<int> f;
        for(auto x:mp)
            f.push_back(x.second);
        sort(f.begin(),f.end());
        int c = 0;
        for(int i = f.size()-2;i>=0;i--){
            if(f[i] == f[i+1])
            {   
                c++;
                f[i]--;
            }
        }
        return c;
    }
};


