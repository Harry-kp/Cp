class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    bool solve(vector<vector<char>>& board, int i, int j, string word)
    {
        if(word.size() == 1)
            return board[i][j] == word[0];

        bool ans = false;
        if(board[i][j] == word[0])
        for(int k=0;k<4;k++){
            if(i+dx[k]>=0 and i+dx[k]<board.size() and j+dy[k]>=0 and j+dy[k]<board[0].size() and board[i+dx[k]][j+dy[k]]!='.')
            {char tmp = board[i][j];
            board[i][j] = '.';
            ans|=solve(board, i+dx[k], j+dy[k],word.substr(1,16));
            board[i][j] = tmp;}
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0;i<board.size();i++)
        for(int j = 0;j<board[0].size();j++)
            if(solve(board,i,j,word))
                return true;
        return false;
    }
};