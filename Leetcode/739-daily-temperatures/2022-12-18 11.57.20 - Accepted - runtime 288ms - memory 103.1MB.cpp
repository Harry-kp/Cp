class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        stack<int> st;
        int n = tem.size();

        vector<int> ans(n,0);

        for(int i = 0;i<n;i++){
            while(!st.empty() and tem[st.top()]<tem[i]){
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;        
    }
};