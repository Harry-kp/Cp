#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define MP make_pair
#define EB emplace_back
#define MOD 1000000007
#define int long long int
#define S second
#define F first
#define debug1 cout << "debug1" << '\n'
#define debug2 cout << "debug2" << '\n'
#define debug3 cout << "debug3" << '\n'

// int dr[] = {0,-1,0,1,-1,-1,1,1};
// int dc[] = {-1,0,1,0,-1,1,1,-1};

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

void solve()
{
    int n, k, x;
    cin >> n;
    vector<int> adj[n];
    vector<int> deg(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> x;
            x--;
            adj[x].EB(i);
            deg[i]++;
        }
    }

    vector<int> dist(n,0);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 0)
        {
            q.push(i);
            dist[i] = 1;
        }
    }
    
    int cnt = 0,ans = -1;
    while (!q.empty())
    {
        cnt++;
        x = q.front();
        // ans.EB(x);
        q.pop();

        for (auto v : adj[x])
        {
            deg[v]--;
            if(v<x){
                dist[v] = max(dist[x]+1,dist[v]);
            }else{
                dist[v] = max(dist[x], dist[v]);
            }
            if (deg[v] == 0)
                q.push(v);
        }
        // ans = max(ans,dist[x]);
    }
    if(cnt!=n){
        cout<<-1<<'\n';
        return ;
    }
    for(auto x:dist)
        ans = max(ans,x);
    cout<<ans<<'\n';
}

int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
