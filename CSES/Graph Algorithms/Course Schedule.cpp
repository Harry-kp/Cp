#include <bits/stdc++.h>
#define int long long 
using namespace std;


void topological_sort(vector<int> adj[],vector<int>  &deg,int n){
    int i,j;
    
    queue<int> q;
    
    for(i = 1;i<=n;i++){
        if(deg[i] == 0)
            q.push(i);
    }
    
    vector<int> ans;
    
    int cnt = 0;
    while(!q.empty()){
        cnt++;
        int x = q.front();
        ans.emplace_back(x);
        q.pop();
        
        for(auto tmp:adj[x]){
            deg[tmp]--;
            
            if(deg[tmp] == 0)
                q.push(tmp);
        }
        
        
    }
    
    if(cnt != n){
        cout<<"IMPOSSIBLE\n";
    }else{
        for(auto x:ans)
            cout<<x<<" ";
        cout<<'\n';
    }
}


int32_t main() {
    int n,m,a,b,i,j;
    cin>>n>>m;
    
    vector<int> adj[n+1];
    vector<int> deg(n+1,0);
    for (i = 0;i<m;i++){
        cin>>a>>b;
        deg[b]++;
        adj[a].emplace_back(b);
        
    }
    
    topological_sort(adj,deg,n);
    
    
    
}
