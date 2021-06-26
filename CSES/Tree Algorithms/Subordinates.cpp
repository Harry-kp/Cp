#include <bits/stdc++.h>
#define int long long 
using namespace std;


void dfs(int par,vector<int> adj[],vector<int> &visited,vector<int> &child){
    
    visited[par] = 1;
    child[par]  = 1;
    for(auto x:adj[par]){
        if(!visited[x]){
            dfs(x,adj,visited,child);
        }
        
        child[par] += child[x];
    }
}

int32_t main(){
    int n,x;
    cin>>n;
    vector<int> adj[n+1];
    
    for(int i = 2;i<=n;i++){
        cin>>x;
        adj[x].emplace_back(i);
    }
    
    vector<int> child(n+1,0),visited(n+1,0);
    dfs(1,adj,visited,child);
    for(int i = 1;i<=n;i++)
        cout<<child[i]-1<<" ";
    cout<<'\n';
    
}
