class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int p = pow(2,k);
        if(n-k+1<p)return false;
        
        vector<int> res(p);
        int x = 0;
        int i = 0;
        for(;i<k;i++){
            x<<=1;
            x|=(s[i]-'0');
        }
        res[x]=1;
        for(;i<n;i++){
            x = x&~(1<<(k-1));
            x<<=1;
            x|=(s[i]-'0');
            res[x]=1;
        }
        
        for(auto x:res){
            if(x==0)return false;
        }
        return true;
        
    }
};