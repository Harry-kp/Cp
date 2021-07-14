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

vector<vector<int>> adj;
vector<int> tin, tout, dist, visited;
vector<vector<int>> up;
int cnt, l;

void dfs(int u, int p = -1)
{
    tin[u] = cnt++;
    up[u][0] = p;

    for (int i = 1; i <= l; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];

    for (auto v : adj[u])
    {
        if (v == p)
            continue;
        if (tin[v] == -1)
            dfs(v, u);
    }
    tout[u] = cnt++;
}

bool isancest(int a, int b)
{
    return (tin[a] <= tin[b] and tout[a] >= tout[b]);
}

int lca(int a, int b)
{
    if (isancest(a, b))
        return a;
    if (isancest(b, a))
        return b;

    for (int i = l; i >= 0; i--)
        if (!isancest(up[a][i], b))
            a = up[a][i];

    return up[a][0];
}

void precprocess(int n)
{
    cnt = 0;
    tin.assign(n, -1);
    tout.assign(n, -1);
    dist.resize(n);
    visited.assign(n, 0);
    adj.resize(n);
    int a, b;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        adj[a].EB(b);
        adj[b].EB(a);

        // adj[b].EB(a);
    }

    l = ceil(log2(n));
    up.resize(n, vector<int>(l + 1));
}

void bfs(int s)
{
    visited[s] = 1;
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    int u;
    while (!q.empty())
    {
        // debug1;
        u = q.front();
        q.pop();

        for (auto v : adj[u])
        {   
            if (!visited[v])
            {
                visited[v] = 1;
                dist[v] = 1 + dist[u];
                q.push(v);
            }
        }
    }
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
        int n, q, a, b;
        cin >> n >> q;
        precprocess(n);
        dfs(0, 0);
        bfs(0);

        

        for (int i = 0; i < q; i++)
        {
            cin >> a >> b;
            a--;
            b--;
            cout << dist[a] + dist[b] - 2 * dist[lca(a, b)] << '\n';
        }
    }
}