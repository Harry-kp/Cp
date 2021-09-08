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

const int N = 2*1e5 + 5;

int parent[N],subSum[N],subSize[N],ans[N],n;

vector<int> adj[N];

void preprocess(int u,int p=-1){
    subSize[u] = 1;
    subSum[u] = 0;
    for(int v:adj[u]){
        if(v!=p){
            preprocess(v,u);
            subSize[u]+=subSize[v];
            subSum[u]+= subSize[v]+subSum[v];
        }
    }
}

void solve(int u,int p = -1){
    ans[u] = ans[p]-subSum[u]-subSize[u] + (n-subSize[u])+subSum[u];

    for(auto v:adj[u])
        if(v!=p)
            solve(v,u);
}

int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int a,b;cin>>n;
        for(int i =1 ;i<n;i++){
            cin>>a>>b;
            adj[a].EB(b);
            adj[b].EB(a);
        }
        preprocess(1);

        solve(1,1);
        ans[1] = subSum[1];

        for(auto v:adj[1])
            solve(v,1);
        for(int i = 1;i<=n;i++)
            cout<<ans[i]<<" ";
            cout<<'\n';

    }
}