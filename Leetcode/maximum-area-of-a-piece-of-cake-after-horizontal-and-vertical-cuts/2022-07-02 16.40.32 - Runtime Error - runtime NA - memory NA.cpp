class Solution {
public:
    int maxArea(int h, int w, vector<int>& H, vector<int>& V)
    {
        const int mod = 1e9+7;
        H.push_back(h);
        V.push_back(w);
        sort(H.begin(),H.end());
        sort(V.begin(),V.end());
        
        int mx1 = H[0];
        for(int i = 1;i<H.size();i++){
            mx1 = max(mx1,H[i]-H[i-1]);
        }
        int mx2 = V[0];
        for(int i = 1;i<V.size();i++){
            mx2 = max(mx2,V[i]-V[i-1]);
        }
        
        long long int res =  (mx1%mod * mx2%mod)%mod;
        return res;
    }
};