class Solution {
public:
    vector<int> res;
    int ans = 0;
    void solve(int i,int n,vector<int>& A,vector<int> B,int x){
        if(i==12)
        {
            
            if(x>ans){
                res=B;
                ans= x;
            }
            return ;
            
        }
        B.push_back(0);
        solve(i+1,n,A,B,x);
        B.pop_back();
        
        if(A[i] == 0){
            if(n>=1){
                B.push_back(1);
                solve(i+1,n-1,A,B,x+i);
                B.pop_back();
            }
        }else{
            if(n>A[i]){
                B.push_back(A[i]+1);
                solve(i+1,n-1-A[i],A,B,x+i);
                B.pop_back();
            }
        }
        
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        solve(0,numArrows,aliceArrows,{},0);
        return res;
    }
};