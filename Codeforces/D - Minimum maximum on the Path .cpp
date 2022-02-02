#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define int long long int

vector<pair<int,int>> adj[100000+5];
int n,m,d;
vector<int> ans;

bool good(int m){
    queue<int> q;

    bool visited[n+1];
    int pred[n+1],dist[n+1];
    for(int i = 0;i<=n;i++){
        pred[i]=-1;
        dist[i]= 100000000;
        visited[i] = false;
    }

    visited[1] = true;
    dist[1] = 0;
    pred[1] = -1;

    q.push(1);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto v:adj[u]){
            if(visited[v.first] == false and v.second<=m){
                visited[v.first]=true;
                dist[v.first] = dist[u]+1;
                pred[v.first]=u;
                q.push(v.first);

                if(v.first == n)
                    break;
            }
        }
    }

    if(visited[n] == false or dist[n]>d)return false;
    
    vector<int> path;
    int crawl = n;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    reverse(path.begin(),path.end());
    ans = path;
    return true;
}   

int solve(){
    int l = -1;
    int r = 1000000009;

    while(l+1<r){
        int m = (l+r)/2;
        if(good(m))
            r=m;
        else
            l=m;
    }
    return r;
}


int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        
        cin>>n>>m>>d;
        int a,b,c;
        for(int i = 0;i<m;i++){
            cin>>a>>b>>c;
            adj[a].push_back({b,c});
        }

        int cur = solve();

        if(cur == 1000000009)   
            cout<<-1<<'\n';
        else
            {
                // cout<<cur<<'\n';
                cout<<ans.size()-1<<'\n';
                for(auto x:ans)
                    cout<<x<<" ";
                cout<<'\n';
            }
    
    }
}
