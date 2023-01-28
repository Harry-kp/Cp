class Solution {
public:
    unordered_map<int,int> m1;
    
    int solve(int n){
        if(n<=0)return 0;
        
        if(m1.find(n)!=m1.end())return m1[n];
        
        bool flag = false;
        int ans = 10000000;
        if(n%2 == 0){
            flag = true;
            ans = min(ans,1+solve(n-n/2));}
        if(n%3 == 0){
            flag = true;
            ans = min(ans,1+solve(n-2*(n/3)));
        }
        // if(!flag)
            ans = min(ans,1+solve(n-1));
        
        m1[n] = ans;
        return ans;
        
    }
    int minDays(int n) {
        return solve(n);
    }
};