class Solution {
public:
    unordered_map<int,int> mp;
    int pow(int n){
        if(n == 1)
            return 0;
        if(mp.count(n))return mp[n];
        return mp[n] = n&1?(1+pow(3*n+1)):(1+pow(n/2));
    }
    
    int getKth(int lo, int hi, int k) {
        
        vector<int> a;
        for(int i = lo;i<=hi;i++){
            a.emplace_back(i);
            
        }
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