class Solution {
public:
    string solve(int& i,string& s){
        int n = s.size();
        string res = "";
        while(i<n){
            if(s[i] == ']'){
                i++;
                return res;
            }
                
            if(s[i]-'a'>=0 and s[i]-'a'<26){
                res+=s[i];
                i++;
            }
            else{
                int val = 0;
                while(i<n and s[i]-'0'>=0 and s[i]-'0'<9)
                {
                    val = val*10+(s[i]-'0');
                    i++;
                }
                i++;
                string str1 = solve(i,s);
                string str2 = "";
                for(int j = 0;j<val;j++)
                    str2+=str1;
                res+=str2;
            }
        }
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        return solve(i,s);
    }
};