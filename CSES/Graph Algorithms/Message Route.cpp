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

int visited[100005], preceed[100005], dist[100005];
vector<int> adj[100005];

void bfs(int u)
{
    memset(visited, 0, sizeof(visited));
    memset(preceed, -1, sizeof(preceed));
    memset(dist, -1, sizeof(dist));

    visited[u] = 1;

    list<int> queue;
    queue.push_back(u);

    while (!queue.empty())
    {
        int x = queue.front();
        queue.pop_front();

        for (int i : adj[x])
            if (!visited[i])
            {
                visited[i] = 1;
                dist[i] = 1 + dist[x];
                preceed[i] = x;
                queue.push_back(i);
            }
    }
}

int32_t main()
{
    fastio;
    int n, m, u, v, i;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].EB(v);
        adj[v].EB(u);
    }

    bfs(1);
    if (dist[n] == -1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << dist[n] + 2 << '\n';
        stack<int> s;

        while (n != -1)
        {
            s.push(n);
            n = preceed[n];
        }
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
    }
}