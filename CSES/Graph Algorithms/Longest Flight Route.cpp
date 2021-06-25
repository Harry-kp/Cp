#include <bits/stdc++.h>
#define int long long 
using namespace std;



void topological_sort(vector<int> adj[],vector<int> badj[],vector<int>  &deg,int n){
    int i,j;
    
    queue<int> q;
    
    for(i = 1;i<=n;i++){
        if(deg[i] == 0)
            q.push(i);
    }
    
    vector<int> par(n+1),dp(n+1);
    
    // kahn algo
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto tmp:adj[x]){
            deg[tmp]--;
            
            if(deg[tmp] == 0)
                q.push(tmp);
        }
        
        
        // dp 
        int mx = -9999999999999;
        int mx_node = -1;
        
        for(auto prev:badj[x]){
            if(mx<dp[prev]+1){
                mx = dp[prev]+1;
                mx_node = prev;
            }
            
        }
        dp[x] = mx;
        par[x] = mx_node;
        if(x == 1)dp[x] = 1;
        
    }
    
    
    // searching if n is reachable from 1
    stack<int> ans;
    bool contains1 = false;
    int tmp = n;
    if(tmp == 1)contains1 = true;
    
    
    while(tmp!=-1 and dp[tmp]>=0){
        ans.push(tmp);
        tmp = par[tmp];
        if(tmp == 1)contains1 = true;
    }
    
    // if reachable print the numbers in the stack
    if(contains1){
        cout<<dp[n]<<'\n';
        while(!ans.empty()){
            cout<<ans.top();
            ans.pop();
            
            if(!ans.empty())cout<<" ";
        }
        cout<<'\n';
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }
}




int32_t main() {
    int n,m,a,b,i,j;
    cin>>n>>m;
    
    vector<int> adj[n+1],badj[n+1];
    vector<int> deg(n+1,0);
    for (i = 0;i<m;i++){
        cin>>a>>b;
        deg[b]++;
        adj[a].emplace_back(b);
        badj[b].emplace_back(a);
        
    }
    
    topological_sort(adj,badj,deg,n);
    
    
    
}
