class Solution {
public:
    bool solve(int i,vector<int>& d,int mask,int n){
        if(i == d.size())
            return n&(n-1) == 0;
        
        int ans = false;
        for(size_t j = 0;j<d.size();j++){
            if((mask&(1<<j))!=0)continue;
            
            if(d[j] == 0 and i==0)continue;
            
            ans|=solve(i+1,d,mask|(1<<j),n*10+d[i]);
            
        }
        return ans;
    }
    bool reorderedPowerOf2(int n) {
        
        vector<int> d;
        
        string s = to_string(n);
        
        for(auto c:s){
            d.push_back(c-'0');
        }
        return solve(0,d,0,0);
    }
};