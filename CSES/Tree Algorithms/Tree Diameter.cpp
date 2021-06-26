#include <bits/stdc++.h>
#define int long long
using namespace std;



pair<int,int> bfs(int src,vector<int> adj[],int n){
    vector<int> dist(n+1,0);
    queue<int> q;
    q.push(src);
    dist[src] =1;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        
        for(auto x:adj[tmp]){
            if(dist[x]!=0)
                continue;
            q.push(x);
            dist[x] = dist[tmp]+1;
        }
    }
    int mx = -999999999999,mx_node = -1;
    
    for(int i = 1;i<=n;i++){
        if(dist[i]>mx){
            mx = dist[i];
            mx_node = i;
        }
    }
    
    return make_pair(mx,mx_node);
}




int32_t main() {
    
int n,a,b;cin>>n;
vector<int> adj[n+1];

for(int i = 0;i<n-1;i++){
    cin>>a>>b;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
}

// farthest point from root
pair<int,int> p1,p2;
p1 = bfs(1,adj,n);

// farthest point from p1
p2 = bfs(p1.second,adj,n);
cout<<p2.first-1<<'\n';
    
}
