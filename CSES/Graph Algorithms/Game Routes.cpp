#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int MOD = 1e9+7;

int topsort(vector<int> adj[],vector<int> badj[],vector<int> deg,int n){
    queue<int> q;
    vector<int> ans;
    for(int i = 1;i<=n;i++){
        if(deg[i] == 0)q.push(i);
    }
    
    vector<int> dp(n+1,0);
    dp[1] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto next:adj[node]){
            deg[next]--;
            
            if(deg[next] == 0){
                q.push(next);
            }
        }
        
        for(auto prev:badj[node]){
            dp[node] = (dp[node] + dp[prev])%MOD;
        }
    }
    return dp[n];
}


int32_t main() {
    int n,m,a,b;
    cin>>n>>m;
    vector<int> adj[n+1],badj[n+1];
    vector<int> deg(n+1,0);
    for(int i = 0;i<m;i++){
        cin>>a>>b;
        adj[a].emplace_back(b);
        badj[b].emplace_back(a);
        deg[b]++;
    }
    
    cout<<topsort(adj,badj,deg,n)<<'\n';
    
    
}
