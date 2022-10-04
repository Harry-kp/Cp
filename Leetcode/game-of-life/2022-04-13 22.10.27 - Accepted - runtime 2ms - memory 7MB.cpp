class Solution {
public:
    int mask[4] = {0,1,0,1};
    
    int findActiveNeighbour(int i,int j,int n,int m,vector<vector<int>>& board){
        int dr[] = {0,-1,0,1,-1,-1,1,1};
        int dc[] = {-1,0,1,0,-1,1,1,-1};
         int act = 0;
        for(int x = 0;x<8;x++){
            if(dr[x]+i>=0 and dr[x]+i<n and dc[x]+j>=0 and dc[x]+j<m){
                act+=board[dr[x]+i][dc[x]+j];
            }
        }
        return act;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int act = findActiveNeighbour(i,j,n,m,board);
                if(board[i][j]==1){
                    if(act<2)
                        ans[i][j]=0;
                    else if(act>3)
                        ans[i][j] = 0;
                    else
                        ans[i][j] = 1;
                }
                else
                    if(act == 3)
                        ans[i][j] = 1;
                        
            }
        }
        board=ans;
        
    }
};