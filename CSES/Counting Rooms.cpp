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

int grid[1002][1002];

void dfs(int i, int j, int n, int m)
{   
    if (i >= 0 and i < n and j >= 0 and j < m and grid[i][j])
    {
        grid[i][j] = 0;
        dfs(i + 1, j, n, m);
        dfs(i - 1, j, n, m);
        dfs(i, j + 1, n, m);
        dfs(i, j - 1, n, m);
    }
}

int32_t main()
{
    fastio;
    int n, m, i, j;
    char c;
    cin >> n >> m;

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            cin >> c;
            if (c == '#')
                grid[i][j] = 0;
            else
                grid[i][j] = 1;
        }
    int ans = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            if (grid[i][j])
            {
                dfs(i, j, n, m);
                ans++;
            }
    }
    cout << ans << '\n';
}
