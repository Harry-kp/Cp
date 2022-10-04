class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(words.begin(),words.end());
        for(auto x:words){
            string tmp="";
            for(int i = x.size()-1;i>=0;i--){
                tmp = tmp+x[i];
                if(s.find(tmp)!=s.end())
                    s.erase(s.find(tmp));
            }
        }
        int ans = 0;
        
        for(auto x:s)
            ans+=x.size();
        return ans;
    }
};