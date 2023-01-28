class Solution {
public:
    vector<int> parent;
    
    int find(int i){
        return parent[i] == i?i:(parent[i] = find(parent[i]));
    }
    
    void _union(int u,int v){
        int a = find(u);
        int b = find(v);
        
        parent[b] = a;
        
    }
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        parent = vector<int>(n);
        vector<int> vis(n);
        for(int i = 0;i<n;i++)
            parent[i]=i;
        
        for(auto e:edges)
        {
            if(vis[e[1]])continue;
            _union(e[0],e[1]);
            vis[e[1]]=1;
        }
        
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(parent[i] == i)
                ans.push_back(i);
        }
        return ans;
    }
};