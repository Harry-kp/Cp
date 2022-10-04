class Solution {
public:
    int dx[8] = {0,-1,0,1,-1,-1,1,1};
    int dy[8] = {-1,0,1,0,-1,1,1,-1};
    
    bool ok(char c,int i,int j,vector<vector<int>>& vis,vector<vector<char>>& board){
        if(i>=0 and j>=0 and i<board.size() and j<board[0].size() and  board[i][j] == c)
            return true;
    return false;
    }
    
    
    void dfs(int i,int j,int src,vector<vector<int>>& vis,set<string>& ans,vector<vector<char>>& board,vector<vector<int>>& trie,vector<pair<bool,string>>& terminal){
        
        if(terminal[src].first){
            ans.insert(terminal[src].second);
        }
        
        for(int c = 0;c<26;c++){
            int tmp = trie[src][c];
            if(tmp!=0){
                for(int d = 0;d<8;d++){
                    if(ok(char(c+'a'),i+dx[d],j+dy[d],vis,board)){
                        vis[i+dx[d]][j+dy[d]] = 1;
                        dfs(i+dx[d],j+dy[d],tmp,vis,ans,board,trie,terminal);
                    }
                }
            }
        }
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
//         create trie
        
        vector<vector<int>> trie(1,vector<int>(26));
        vector<pair<bool,string>>terminal;
        terminal.push_back({false,""});
        
        int N = 0;
        
        for(auto s:words){
            int node =  0;
            for(auto c:s){
                if(trie[node][c-'a'] == 0)
                {
                    trie.push_back(vector<int>(26));
                    terminal.push_back({false,""});
                    trie[node][c-'a'] = ++N;
                }
                node = trie[node][c-'a'];
            }
            terminal[node].first = true;
            terminal[node].second = s;
        }
        
        //queries
        int n = board.size();
        int m  = board[0].size();
        vector<vector<int>> vis;
        set<string> ans;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                vis.resize(n,vector<int>(m));
                dfs(i,j,0,vis,ans,board,trie,terminal);
            }
        }
        
        vector<string> out(ans.begin(),ans.end());
        return out;
    }
};