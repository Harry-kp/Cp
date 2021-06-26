// Using binary lifting technique
#include <bits/stdc++.h>
#define int long long
using namespace std;


const int N = 2e5 + 5;
const int ex = 30;

int up[N][ex];
// bool vis[N];

// void dfs(int s,int p,vector<int> adj[]){
//     up[s][0] = p;
//     vis[s] = 1;
//     for(auto x:adj[s]){
//         if(!vis[x])
//         dfs(x,s,adj);
//     }
// }


int32_t main() {
    int n,q,tmp;
    cin>>n>>q;
    memset(up,-1,sizeof(up));
    
    for(int i = 1;i<=n;i++){
        cin>>up[i][0];
    }
    

    
    // preprocess in nlogn
    for(int j = 1;j<ex;j++){
        for(int i = 1;i<=n;i++)
                up[i][j] = up[up[i][j-1]][j-1];
    }
    
    // solve queries 
    int x,k;
    for(int i = 1;i<=q;i++){
        cin>>x>>k;
        
        for(int i = 0;i<ex;i++){
            if(k&(1<<i))
                x = up[x][i];
        }
        cout<<x<<'\n';
    }
    
}
