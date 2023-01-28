class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        for(auto x:s){
            if(x == '{' or x == '(' or x == '['){
                st.push(x);
            }else{
                if(x == ']')
                {
                    if(st.empty() or st.top()!='[')
                        return false;
                    else st.pop();
                }
                else if(x == '}')
                {
                    if(st.empty() or st.top()!='{')
                        return false;
                    else st.pop();
                }
                else{
                    if(st.empty() or st.top()!='(')
                        return false;
                    else st.pop();
                }
            }
        }
        if(st.empty())return true;
        return false;
    }
};