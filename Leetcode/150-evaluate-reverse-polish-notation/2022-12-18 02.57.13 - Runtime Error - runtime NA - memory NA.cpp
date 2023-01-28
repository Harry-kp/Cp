class Solution {
public:
    int evalRPN(vector<string>& A) {
        stack<int> st;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != "+" && A[i] != "-" && A[i] != "/"
            && A[i] != "*") {
            st.push(stoi(A[i]));
            continue;
        }
        else {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (A[i] == "+")
                st.push(a + b);
            else if (A[i] == "-")
                st.push(a - b);
            else if (A[i] == "*")
                st.push(a * b);
            else
                st.push(a / b);
        }
    }
    return st.top();
    }
};