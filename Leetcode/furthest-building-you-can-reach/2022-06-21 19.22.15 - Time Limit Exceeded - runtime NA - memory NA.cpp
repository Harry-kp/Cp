class Solution {
public:
    int solve(int i,const vector<int>& h,int b,int l){
        // cout<<i<<" "<<b<<" "<<l<<"\n";
        int n = h.size();
        if(i == n-1)
            return i;
        
        int ans = i;
        if(h[i]>=h[i+1])
            return solve(i+1,h,b,l);
        
        if(h[i+1]-h[i]<=b)
            ans = max(ans,solve(i+1,h,b-(h[i+1]-h[i]),l));
        if(l>0)
            ans= max(ans,solve(i+1,h,b,l-1));
        return ans;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        return solve(0,heights,bricks,ladders);
    }
};