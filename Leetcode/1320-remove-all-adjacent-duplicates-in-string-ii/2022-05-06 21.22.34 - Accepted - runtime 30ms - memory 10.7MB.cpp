class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
                
        for(int i = 0;i<s.size();i++){
            
            if(!st.empty() && s[i] == st.top().first){
                auto tmp = st.top();
                st.pop();
                tmp.second++;
                st.push(tmp);
            }else
                st.push({s[i],1});
            
            //remove k chars
            if(!st.empty() && st.top().second == k)
                st.pop();
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