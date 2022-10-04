class Solution {
public:
    int color[105];
    
    bool bfs(int s,vector<vector<int>>& graph){
        color[s] = 0;
        
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto v:graph[node]){
                if(color[v] == -1){
                    color[v] = !color[node];
                    q.push(v);
                }
                    
                else if(color[node] == color[v])return false;
                    
            }
        }
        for(int i = 0;i<graph.size();i++)
            if(color[i] == -1)return false;
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        memset(color,-1,sizeof color);
        return bfs(0,graph);
    }
};