class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> super(26,0);
        
        for(auto x:words2){
            vector<int> f(26,0);
            for(auto c:x)
                f[c-'a']++;
            
            for(int i = 0;i<26;i++)
            super[i] = max(super[i],f[i]);
        }
        
        vector<string> res;
        bool flag;
        for(auto x:words1){
            vector<int> tmp = super;
            flag = true;
            for(auto c:x)
                tmp[c-'a']--;
            
            for(int i = 0;i<26;i++)
                if(tmp[i]>0){
                    flag=false;
                    break;
                }
            if(flag)res.push_back(x);
            
        }
        return res;
        
        
    }
};