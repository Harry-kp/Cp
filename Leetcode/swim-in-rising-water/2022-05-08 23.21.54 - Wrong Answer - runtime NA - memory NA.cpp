class Solution {
public:
    int dr[4] = {0,-1,0,1};
    int dc[4] = {-1,0,1,0};
    void dfs(int r,int c,const vector<vector<int>>& grid, vector<vector<bool>>& vis,const int& t){
        vis[r][c] = true;
        int n = grid.size();
        for(int k = 0;k<4;k++){
            int i = r+dr[k];
            int j = c+dc[k];
            
            if(i>=0 and i<n and j>=0 and j<n and !vis[i][j] and grid[i][j]<=t)
                dfs(i,j,grid,vis,t);
        }
        

    }
    
    bool canswim(const int& t,const vector<vector<int>>& grid){
        int n = grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        
        dfs(0,0,grid,vis,t);
        return vis[n-1][n-1];
    }
    int swimInWater(vector<vector<int>>& grid) {
        
        int l = grid[0][0];
        int r = 3000;
        
        while(r-l>1){
        int m = (r+l)/2;
            if(canswim(m,grid))
                r=m;
            else
                l=m;
        }
        return r;
    }
};