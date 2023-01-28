class Solution {
public:
    int maxScore(vector<int>& p, int k) {
        int n = p.size()-k;
        int s = 0;
        int par=0;
        
        for(auto x:p)s+=x;
        int i = 0;
        for(;i<n;i++)par+=p[i];
        int min1 = par;
        for(;i<p.size();i++){
            par = par - p[i-n]+p[i];
            min1 = min(min1,par);
        }
        return s-min1;
    }
};