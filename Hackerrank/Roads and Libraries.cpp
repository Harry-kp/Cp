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

int visited[100005];

void dfs(int v, vector<int> list[], int &c)
{
    visited[v] = 1;
    for (int x : list[v])
    {
        if (!visited[x])
        {
            c++;
            dfs(x, list, c);
        }
    }
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;
    while (t--)
    {
        memset(visited, 0, sizeof(visited));
        int n, m, clib, crod, i, u, v;
        cin >> n >> m >> clib >> crod;

        vector<int> list[n + 2];
        for (i = 0; i < m; i++)
        {
            cin >> u >> v;
            list[u].emplace_back(v);
            list[v].emplace_back(u);
        }
        int lib = 0, roads = 0, tmp, c;
        for (i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                c = 0;
                dfs(i, list, c);
                roads += c;
                lib++;
            }
        }
        cout << min(lib * clib + roads * crod, n * clib) << '\n';
    }
}
