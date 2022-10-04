struct Trie{
    vector<vector<int>> next;
    vector<bool> is_terminal;
    int N;
    void init(){
        next.push_back(vector<int>(26,0));
        is_terminal.push_back(false);
        N=0;
    }
    
    void insert(string word){
        int node = 0;
        for(char c:word){
            if(next[node][c-'a'] == 0){
                //add new node
                next.push_back(vector<int>(26,0));
                is_terminal.push_back(false);
                next[node][c-'a'] = ++N;
                
            }
            node = next[node][c-'a'];
        }
        is_terminal[node] = true;
    }
    
};

void dfs(int node,string& word,vector<string>& result,const vector<vector<int>>& next,const vector<bool>& is_terminal){
    if(result.size() == 3)return;
    
    if(is_terminal[node])
        result.push_back(word);
    for(int i = 0;i<26;i++){
        if(next[node][i] != 0){
            word+=char('a'+i);
            dfs(next[node][i],word,result,next,is_terminal);
            word.pop_back();
        }
            
        
    }
}
vector<string> get3words(string& prefix,const vector<vector<int>>& next,const vector<bool>& is_terminal){
    vector<string> result;
    int node = 0;
    
    for(auto c:prefix){
            if(next[node][c-'a'] == 0)return result;
            node = next[node][c-'a'];
    }
    
    dfs(node,prefix,result,next,is_terminal);
    return result;
}

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        struct Trie trie;
        trie.init();
        for(string word:products)
            trie.insert(word);
        
        vector<vector<string>> ans;
        string prefix = "";
        for(auto c:searchWord){
            prefix+=c;
            ans.push_back(get3words(prefix,trie.next,trie.is_terminal));
            
        }
        return ans;
        
    }
    
    
    
    
};