class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int i,vector<int>& tmp,vector<vector<int>>& graph){
        if(i == graph.size()-1){
            
            ans.push_back(tmp);
            return;
        }
        for(int j = 0;j<graph[i].size();j++){
            tmp.push_back(graph[i][j]);
            dfs(graph[i][j],tmp,graph);
            tmp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<int> tmp;
        tmp.push_back(0);
        
        dfs(0,tmp,graph);
        return ans;
    }
};