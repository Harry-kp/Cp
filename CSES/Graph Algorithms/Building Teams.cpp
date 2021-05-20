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

int color[100005];
vector<int> adj[100005];

bool bfs(int u)
{

    color[u] = 1;
    list<int> queue;
    queue.push_back(u);

    while (!queue.empty())
    {
        int x = queue.front();
        queue.pop_front();
        for (int i : adj[x])
        {
            if (color[i] == -1)
            {
                color[i] = 1^color[x];
                queue.push_back(i);
            }
            else if (color[x] == color[i])
                return false;
            // else cout<<"hsa ";
        }
    }
    return true;
}

int32_t main()
{
    fastio;
    memset(color,-1,sizeof(color));
    int n, m, u, v, i;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> u >> v;
        // cout<<color[i];
        adj[u].EB(v);
        adj[v].EB(u);
    }

    for(i = 1;i<=n;i++){
        if(color[i] == -1){
            // cout<<i<<" ";
            if(!bfs(i)){
                cout<<"IMPOSSIBLE\n";
                return 0;
        }
    }
    }
    for(i = 1;i<=n;i++)
    cout<<color[i]+1<<" ";
}
