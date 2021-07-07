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

int dr[] = {0, -1, 0, 1};
int dc[] = {-1, 0, 1, 0};
const int N = 55;
char grid[N][N];

int visited[N][N];

void dfs(int i, int j, int n, int m)
{
    visited[i][j] = 1;

    for (int c = 0; c < 4; c++)
    {
        if (i + dr[c] < n and i + dr[c] >= 0 and j + dc[c] < m and j + dc[c] >= 0)
        {
            if (grid[i + dr[c]][j + dc[c]] == '#' and !visited[i + dr[c]][j + dc[c]])
            {
                dfs(i + dr[c], j + dc[c], n, m);
            }
        }
    }
}

int alldfs(int n, int m)
{
    memset(visited, 0, sizeof(visited));
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout<<'\n';
    // }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '#' and !visited[i][j])
            {
                dfs(i, j, n, m);
                // debug2;
                cnt++;
            }
        }
    // cout << cnt << '\n';
    return cnt;
}

bool ans1(int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '#')
            {
                int cnt = 0;
                grid[i][j] = '.';
                cnt = alldfs(n, m);
                // cout<<cnt<<'\n';
                if (cnt > 1)
                    return true;
                grid[i][j] = '#';
            }
        }
    return false;
}
int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == '#')
                {
                    cnt++;
                }
            }

        // -1 case
        if (cnt <= 2)
            cout << -1 << '\n';
        else if (ans1(n, m))
        {
            cout << 1 << '\n';
        }
        else
            cout << 2 << '\n';
    }
}