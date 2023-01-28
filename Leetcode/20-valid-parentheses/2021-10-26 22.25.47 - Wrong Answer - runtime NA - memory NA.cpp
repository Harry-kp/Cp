class Solution {
public:
    bool solve(string s,char open,char close){
        stack<char> st;
        for(auto x:s){
            if(x == open){
                st.push(x);
            }else if(x == close){
                if(st.empty())
                    return false;
                else{
                    st.pop();
                }
            }
        }
        if(st.empty())return true;
        return false;
    }
    
    bool isValid(string s) {
        
        return solve(s,'{','}') and solve(s,'[',']') and solve(s,'(',')');
    }
};