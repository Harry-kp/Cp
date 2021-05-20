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

int visited[100005], parent[100005];
vector<int> adj[100005];
int st, ed;

bool dfs(int src, int father)
{
    parent[src] = father;
    visited[src] = 1;
    for (int dest : adj[src])
    {
        if (!visited[dest])
        {
            if (dfs(dest, src))
                return true;
        }
        else
        {
            if (dest != father)
            {
                st = dest;
                ed = src;
                return true;
            }
        }
    }
    return false;
}

int32_t main()
{
    fastio;
    memset(visited, 0, sizeof(visited));
    int n, m, a, b, i;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].EB(b);
        adj[b].EB(a);
    }
    bool flag = false;
    for (i = 1; i <= n; i++)
    {
        if (!visited[i])
            if (dfs(i, -1))
            {
                flag = true;
                break;
            }
    }

    if (!flag)
        cout << "IMPOSSIBLE\n";
    else
    {
        ;
        list<int> ans;
        ans.push_back(st);

        while (ed!=st)
        {
            ans.push_front(ed);
            ed = parent[ed];
        }
        ans.push_front(st);
        cout << ans.size() << '\n';
        for (auto x : ans)
        {
            cout << x << " ";
        }
    }
}