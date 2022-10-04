class Solution {
public:
    int dig(string s){
        int r = 0;
        for(int i = 0;i<s.size();i++)
            r = r*10 + (s[i]-'0');
        return r;
    }
    vector<int> solve(string s){
        if(s.size() == 0)
            return vector<int>();
        if(s.size() == 1 or s.size() == 2)
            return vector<int>({dig(s)});
        int n = s.size();
        vector<int> res;
        for(int i = 0;i<n-1;i++){
            if(s[i] == '+' || s[i] == '-' or s[i] == '*')
            {
             vector<int> left = solve(s.substr(0,i));   
             vector<int> right = solve(s.substr(i+1));
                
            if(!left.size())return right;
            if(!right.size())return left;
                
                
            for(auto l:left)
                for(auto r:right)
                   switch (s[i]) {
                    case '-':
                        res.push_back(l-r);
                        break;
                    case '+':
                        res.push_back(l+r);
                        break;
                    case '*':
                        res.push_back(l*r);
                        break;
                    }
            
            }
    }
        return res;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};