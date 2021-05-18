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
#define int long long
#define S second
#define F first
#define endl '\n'
#define FOR(var, len) for (var = 0; var < len; var++)
#define debug1 cout << "debug1" << '\n'
#define debug2 cout << "debug2" << '\n'
#define debug3 cout << "debug3" << '\n'
#define max_l 1000005
#define ii pair<int, int>

vector<int> adj[3 * 100000 + 5];
int count1[3 * 100000 + 5];
int tmp;
bool comp(int &a, int &b)
{

    return count1[a] > count1[b];
}


void dfs(int u,int par)
{
    if (adj[u].size() == 0)
    {
        count1[u] = 1;
        return;
    }

    for (auto x : adj[u])
        if(x!=par)
            dfs(x,u);
    count1[u] = 1;
    sort(adj[u].begin(), adj[u].end(), comp);
    for(int i = 0;i<adj[u].size();i++)
        count1[u] += (i+1)*count1[adj[u][i]];
    
}


int32_t main()
{
    fastio;

    int t;
    cin >> t;
    while (t--)
    {
        memset(adj, 0, sizeof(adj));
        memset(count1, 0, sizeof(count1));

        int n, x, i, u, v;
        cin >> n >> x;
        for (i = 0; i < n - 1; i++)
        {
            cin >> u >> v;
            adj[u].EB(v);
            adj[v].EB(u);  
        }
        dfs(1,-1);
        cout << (count1[1]%MOD * x%MOD)%MOD<<'\n';
    }
}