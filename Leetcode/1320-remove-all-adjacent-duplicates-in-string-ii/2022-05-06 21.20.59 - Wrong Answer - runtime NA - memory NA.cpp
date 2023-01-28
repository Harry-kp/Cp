class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        
        st.push({s[0],1});
        
        for(int i = 1;i<s.size();i++){
            
            //remove k chars
            if(!st.empty() && st.top().second == k)
                st.pop();
            
            if(!st.empty() && s[i] == st.top().first){
                auto tmp = st.top();
                st.pop();
                tmp.second++;
                st.push(tmp);
            }else
                st.push({s[i],1});
        }
        
        string ans = "";
        while(!st.empty())
        {
            auto tmp = st.top();
            for(int i = 0;i<tmp.second;i++)
                ans+=tmp.first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};