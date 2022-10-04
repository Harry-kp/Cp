class Solution {
public:
    void dfs(int src,string so_far,string& ans,const vector<vector<int>> Trie,const vector<bool> terminal){
        if(so_far.size()>ans.size())
            ans = so_far;
        
        for(int c = 0;c<26;c++){
            int tmp = Trie[src][c];
            
            if(tmp!=0 and terminal[tmp])
                dfs(tmp,so_far + char('a'+c),ans,Trie,terminal);
        }
    }
    
    
    string longestWord(vector<string>& words) {
        vector<vector<int>> Trie(1,vector<int>(26,0));
        vector<bool> terminal(1);
        int N = 0;
        for(auto s:words){
            int node = 0;
            for(auto c:s){
                if(Trie[node][c-'a'] == 0){   //add new node
                    terminal.push_back(false);
                    Trie.push_back(vector<int>(26,0));
                    Trie[node][c-'a'] = ++N;
                }
                node = Trie[node][c-'a'];  
            }
            terminal[node] = true;
        }
        
        string ans = "";
        dfs(0,"",ans,Trie,terminal);
        return ans;
    }
};