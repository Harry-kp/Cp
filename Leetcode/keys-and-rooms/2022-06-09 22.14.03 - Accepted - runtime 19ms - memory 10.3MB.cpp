class Solution {
public:
    void dfs(int s,vector<vector<int>>& rooms,vector<bool>& vis){
        vis[s]=true;
        
        for(auto x:rooms[s]){
            if(!vis[x])
                dfs(x,rooms,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n);
        
        dfs(0,rooms,vis);
        for(int i = 0;i<n;i++)
            if(!vis[i])return false;
        return true;
    }
};