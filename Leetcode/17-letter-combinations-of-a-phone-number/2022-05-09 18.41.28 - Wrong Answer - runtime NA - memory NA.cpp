class Solution {
public:
    vector<string> dig[10] = {{},{},{"a","b","c"},{"d","f","e"},{"h","i","g"},{"k","l","j"},{"n","o","m"},{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}};
    vector<string> solve(int i,const string& digits){
        if(i == digits.size())
            return {""};
        
        vector<string> ans;
        
        //if taking only current char
        
        for(auto s:dig[digits[i]-'0']){
            vector<string> tmp = solve(i+1,digits);
            
            for(auto x:tmp)
                ans.push_back(s+x);
        }
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        return solve(0,digits);
    }
};