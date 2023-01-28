class Solution {
public:
    int vis[105][105];
    int dr[4] = {0,-1,0,1};
    int dc[4] = {-1,0,1,0};
    
    void dfs(int i,int j,int k,vector<vector<int>>& heights){
        vis[i][j] = 1;
        for(int l = 0;l<4;l++){
            int a = i+dr[l];
            int b = j + dc[l];
            
            if(a>=0 and b>=0 and a<heights.size()  and b<heights[0].size() and vis[a][b] == 0 and abs(heights[a][b] - heights[i][j])<=k)
                dfs(a,b,k,heights);
        }
    }
    
    bool canReach(int k,vector<vector<int>>& heights){
        memset(vis,0,sizeof vis);
        dfs(0,0,k,heights);
        int r = heights.size();
        int c = heights[0].size();
        if(vis[r-1][c-1] == 1)
            return true;
        return false;
        
    }
    
    int binary(vector<vector<int>>& heights){
        int l = -1;
        int r = 1000005/2;
        
        while(r-l>1){
            int m = (l+r)/2;
            
            if(canReach(m,heights))
                r=m;
            else
                l=m;
        }
        return r;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        return binary(heights);
    }
};