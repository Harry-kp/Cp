class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        
        if(s.size()>t.size())return false;
        
        int s1=0,t1=0;
        while(t1<t.size()){
            if(s[s1]==t[t1])
                s1++,t1++;
            else
                t1++;
        }
        
        if(s1 == s.size())
            return true;
        return false;
    }
};