class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //Bellman ford O(EV)
        
        vector<int>dist(n,INT_MAX);
        k--;
        dist[k]=0;
        for(int i = 0;i<n-1;i++){
            for(auto e:times){
                int u=e[0],v=e[1],w=e[2];
                u--;v--;
                if(dist[u] != INT_MAX and dist[u]+w<dist[v])
                    dist[v]=w+dist[u];
            }
        }
        
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans = max(ans,dist[i]);
        }
        return ans == INT_MAX?-1:ans;
    }
};