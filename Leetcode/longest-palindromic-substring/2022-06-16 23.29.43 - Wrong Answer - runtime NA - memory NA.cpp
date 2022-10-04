class Solution {
public:
    string solve(int l,int r,const string& s){
        if(l>r)
            return "";
        
        string ans = "";
        if(s[l] == s[r]){
            ans+=s[l] + solve(l+1,r-1,s);
            if(l!=r)
                ans+=s[r];
            return ans;
        }
        string a = solve(l+1,r,s);
        string b = solve(l,r-1,s);
        return (a.size()>b.size())?a:b;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        return solve(0,n-1,s);
        
    }
};