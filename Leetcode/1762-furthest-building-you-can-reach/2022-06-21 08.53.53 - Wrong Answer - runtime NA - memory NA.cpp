class Solution {
public:
    int solve(int i,const vector<int>& h,int b,int l){
        cout<<i<<" "<<b<<" "<<l<<"\n";
        int n = h.size();
        
        if(i==n-1)return i;
        int ans = i;
        int pre = i == 0?10000000:h[i-1];
        if(pre>=h[i]){
            ans = max(ans, solve(i+1,h,b,l));
            return ans;
        }
        if(b>=(h[i]-pre))
            ans = max(ans,solve(i+1,h,b-(h[i]-pre),l));
        
        if(l>0)
            ans = max(ans,solve(i+1,h,b,l-1));
        return ans>i?ans:i-1;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        return solve(0,heights,bricks,ladders)+1;
    }
};