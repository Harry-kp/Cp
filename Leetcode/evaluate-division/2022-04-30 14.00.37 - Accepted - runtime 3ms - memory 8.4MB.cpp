class Solution {
public:
    unordered_map<string,unordered_map<string,double>> adj;
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        for(int i = 0;i<equations.size();i++){
            string u = equations[i][0];
            string v = equations[i][1];
            
            adj[u][v] = values[i];
            adj[v][u] = 1/values[i];
            adj[u][u] = 1;
            adj[v][v] = 1;
        }
        
        //floyd warshall
        //time complexity:-n**3 = 20*20*20
        for(auto a:adj){
            for(auto b:a.second){
                for(auto c:a.second)
                    adj[b.first][c.first] = adj[b.first][a.first]*adj[a.first][c.first];
            }
        }
        
        //check queries
        //time complexity
        vector<double> ans;
        for(int i = 0;i<queries.size();i++){
            string u = queries[i][0];
            string v = queries[i][1];
            
            if(adj.count(u) == 0 or adj[u].count(v) == 0)
                ans.push_back(-1.00000);
            else
                ans.push_back(adj[u][v]);
        }
        return ans;
        
    }
};