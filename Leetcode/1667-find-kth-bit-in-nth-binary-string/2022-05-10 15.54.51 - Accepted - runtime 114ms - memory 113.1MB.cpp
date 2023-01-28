class Solution {
public:
    string rev_inv(string s){
        string ans = "";
        
        for(int i = s.size()-1;i>=0;i--)
            ans+=s[i]=='0'?'1':'0';
        return ans;
    }
    string solve(int n){
        if(n == 1)
            return "0";
        string s = solve(n-1);
        return s+"1"+rev_inv(s);
    }
    char findKthBit(int n, int k) {
        return solve(n)[k-1];
    }
};