class Solution {
public:
    int color[105];
    
    bool bfs(int s,vector<vector<int>>& graph){
        color[s] = 0;
        
        queue<int> q;
        q.push(s);
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
        return true;
    }
        
    
    bool isBipartite(vector<vector<int>>& graph) {
        memset(color,-1,sizeof color);
        bool ans = true;
        for(int i = 0;i<graph.size();i++)
            if(color[i] == -1)
                ans&=bfs(i,graph);
        return ans;
    }
};