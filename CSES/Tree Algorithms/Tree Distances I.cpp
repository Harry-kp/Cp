#include <bits/stdc++.h>
#define int long long
using namespace std;



vector<int> bfs(int src,vector<int> adj[],int n){
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
    
    
    return dist;
}




int32_t main() {
    
int n,a,b;cin>>n;
vector<int> adj[n+1];

for(int i = 0;i<n-1;i++){
    cin>>a>>b;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
}

// distance of  every point from 1
vector<int> p1,p2,p3;
p1 = bfs(1,adj,n);

// find farthest point
int mx = -9999999999,mx_node = -1;
for(int i = 1;i<=n;i++){
    if(p1[i]>mx){
        mx = p1[i];
        mx_node = i;
    }
}


// distance of  every point from mx_node
p2 = bfs(mx_node,adj,n);

// again find farthest point
mx = -9999999999;mx_node = -1;
for(int i = 1;i<=n;i++){
    if(p2[i]>mx){
        mx = p2[i];
        mx_node = i;
    }
}


// distance of every point from mx_node
p3 = bfs(mx_node,adj,n);

for(int i = 1;i<=n;i++){
    cout<<max(p2[i],p3[i])-1<<" ";
}
cout<<'\n';
}
