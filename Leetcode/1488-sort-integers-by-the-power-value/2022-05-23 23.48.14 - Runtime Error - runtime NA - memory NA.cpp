class Solution {
public:
    int dp[5000];
    int pow(int n){
        if(n == 1)
            return 0;
        if(dp[n]!=-1)return dp[n];
        return dp[n] = n&1?(1+pow(3*n+1)):(1+pow(n/2));
    }
    
    int getKth(int lo, int hi, int k) {
        
        vector<int> a;
        for(int i = lo;i<=hi;i++){
            a.emplace_back(i);
            
        }
        memset(dp,-1,sizeof dp);
        sort(a.begin(),a.end(),[&](const int& a,const int& b){
            int x = pow(a);
            int y = pow(b);
            
            if(x==y)
                return a<b;
            return x<y;
        });
        return a[k-1];
    }
};