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

vector<int> adj[100004];
int visited[100005] = {0};

void dfs(int u, vector<int> &route, int n)
{
    visited[u] = 1;

    for (int x : adj[u])
    {
        if (!visited[x])
        {
            route.emplace_back(x);
            if (x == n)
                return;
            dfs(x, route, n);
        }
    }
}

int32_t main()
{
    fastio;
    int n, m, i, j, u, v;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> route = {1};
    dfs(1, route, n);

    if (find(route.begin(), route.end(), n) != route.end())
    {
        cout<<route.size()<<endl;
        for(auto x:route)
            cout<<x<<" ";
        cout<<endl;
    }
    else cout<<"IMPOSSIBLE\n";
}