class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> f,l;
        
        for(int i = 0;i<s.size();i++){
            if(!f.count(s[i]))
                f[s[i]] = i;
            l[s[i]] = i;
        }
        
        vector<int> ind;
        for(auto k:f){
            ind.push_back(k.second);
        }
        for(auto k:l){
            ind.push_back(k.second);
        }
        
        sort(ind.begin(),ind.end());
        
        int m = ind.size()/2;
        
        return ind[m]-ind[m-1];
    }
};