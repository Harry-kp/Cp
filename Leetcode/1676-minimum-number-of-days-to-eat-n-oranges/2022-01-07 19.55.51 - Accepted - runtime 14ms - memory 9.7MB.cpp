class Solution {
public:
    unordered_map<int,int> m1;
    int solve( int n){
        if(n == 0)return 0;
        if(n == 1)return 1;
        
        if(m1.find(n)!=m1.end())return m1[n];
        
        
        int ans = 10000000;
        
        ans = min(ans,1 + n%3 + solve(n/3));
        ans = min(ans,1 + n%2 + solve(n/2));
        m1[n] = ans;
        return ans;
        
    }
    int minDays(int n) {
        
        return solve(n);
        
    }
};