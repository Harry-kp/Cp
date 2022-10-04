class Solution {
public:
    
    bool cat(int n,int i,string curr,string s,unordered_set<string>& m1){
        
        if(i == n){
            if(m1.find(curr)!=m1.end() or curr == "")return true;
            return false;
        }
        
        
        int ans = false;
        
        for(int j = i;j<n;j++){
            curr+=s[j];
            if(m1.find(curr)!=m1.end())
                ans = ans or cat(n,j+1,"",s,m1);
            else
                ans = ans or cat(n,j+1,curr,s,m1);
        }
        // cout<<curr<<" "<<ans<<'\n';
        return ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> m1;
        for(auto x:wordDict){
            m1.insert(x);
        }
        return cat(s.size(),0,"",s,m1);
    }
};