class Solution {
public:
    
    int minCost(string c, vector<int>& T) {
        // stack<pair<char,int>> st;
        char prevc = '#';
        int previ = 0;
        int ans = 0;
        int n = c.size();
        for(int i = 0;i<n;i++){
            if(prevc != c[i]){
                prevc = c[i];
                previ = T[i];
            }else
            {
                ans+=min(previ,T[i]);
                previ = max(T[i],previ);                
            }
        }
        return ans;
    }
};