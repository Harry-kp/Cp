#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)
#define PI(a, b) pair<a, b>
#define MP make_pair
#define EB emplace_back
#define MOD 1000000007
#define int long long int
#define S second
#define F first
#define FOR(var, len) for (var = 0; var < len; var++)
#define debug1 cout << "debug1" << '\n'
#define debug2 cout << "debug2" << '\n'
#define debug3 cout << "debug3" << '\n'

// Maths Utils
int binExp(int a, int b, int m)
{
    int r = 1;
    while (b)
    {
        if (b % 2 == 1)
            r = (r * a) % m;

        a = (a * a) % m;
        b = b / 2;
    }
    return r;
}

const int N = 1e5+5;
vector<int> adj[N][2];
int vis[N];

void dfs(int s,int m){
    vis[s] = 1;
    for(auto x:adj[s][m]){
        if(!vis[x])
            dfs(x,m);
    }
}



int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n,m,a,b;
        cin>>n>>m;

        for(int i = 0;i<m;i++){
            cin>>a>>b;
            adj[a][0].EB(b);
            adj[b][1].EB(a);
        }

        memset(vis,0,sizeof(vis));
        dfs(1,0);

        for(int i = 1;i<=n;i++){
            if(!vis[i]){
                cout << "NO\n";
                cout<<1<<" "<<i<<'\n';
                return 0;
            }
        }
        memset(vis,0,sizeof(vis));
        dfs(1,1);
        for(int i = 1;i<=n;i++){
            if(!vis[i]){
                cout<<"NO\n";
                cout<<i<<" "<<1<<'\n';
                return 0;
            }
        }
        cout << "YES\n";
    }
}