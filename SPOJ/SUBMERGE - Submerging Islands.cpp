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

const int N = 1e4 + 10;

vector<int> adj[N];
set<int> ans;
int visited[N], dis[N], low[N];
int cnt;
void IS_AP(int island)
{
    ans.insert(island);
}

void dfs(int s, int p = -1)
{
    int child = 0;
    visited[s] = 1;
    dis[s] = low[s] = cnt++;

    for (auto v : adj[s])
    {
        if (v == p)
            continue;
        if (visited[v])

            low[s] = min(low[s], dis[v]);

        else
        {
            dfs(v, s);
            // update low for s from nodes in its dfs spanning tree
            low[s] = min(low[s], low[v]);
            // check AP
            if (low[v] >= dis[s] and p != -1)
            { //p!=-1 for exculding root
                IS_AP(s);
            }
            child++;
        }
    }
    // special case for root
    if (p == -1 and child > 1)
    {
        IS_AP(s);
    }
}

void noOfIsland(int n)
{

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);

    cout << ans.size() << '\n';
}

int32_t main()
{
    fastio;
    int n, m;
    while (1)
    {
        cin >> n >> m;
        if (n == 0 and m == 0)
            break;
        // preprocessing
        cnt = 0;
        for (int i = 0; i < N; i++)
        {
            visited[i] = 0;
            dis[i] = -1;
            low[i] = -1;
            adj[i].clear();
        }

        ans.clear();

        int x, y;

        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            adj[x].EB(y);
            adj[y].EB(x);
        }

        noOfIsland(n);
        for (int i = 0; i < N; i++)
            adj[i].clear();
    }
}