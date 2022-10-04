class Solution {
public:
    vector<string> ans;
    vector<vector<char>> map1 = {{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    
    void solve(string digits,int i,string s){
        if(i == digits.size()){
            ans.push_back(s);
            return;
        }
    
        for(int j = 0;j<map1[digits[i]-'0'].size();j++){
            solve(digits,i+1,s + map1[digits[i]-'0'][j]);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits == "")return {};
        solve(digits,0,"");
        return ans;
    }
};