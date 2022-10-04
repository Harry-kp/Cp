class Solution {
public:
    int dr[8] = {0,-1,0,1,-1,-1,1,1};
    int dc[8] = {-1,0,1,0,-1,1,1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(grid[0][0] or grid[n-1][n-1])
            return -1;
        vector<vector<int>> vis(n,vector<int>(n,0)),dis(n,vector<int>(n,0));
        
        queue<pair<int,int>> q;
        vis[0][0] = 1;
        dis[0][0] = 0;
        q.push({0,0});
        
        while(!q.empty()){
            int i = q.front().first;
            int j  = q.front().second;
            q.pop();
            for(int k = 0;k<8;k++){
                int r = i+dr[k];
                int c = j+dc[k];
                if(r>=0 and r<n and c>=0 and c<n and !vis[r][c] and !grid[r][c])
                {
                    q.push({r,c});
                    dis[r][c]=dis[i][j]+1;
                    vis[r][c]=1;
                }
                    
            }
        }
        return !vis[n-1][n-1]?-1:dis[n-1][n-1]+1;
    }
};