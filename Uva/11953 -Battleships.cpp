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

int dr[] = {0, -1, 0, 1, -1, 1, -1, 1};
int dc[] = {-1, 0, 1, 0, -1, 1, 1, -1};

char grid[102][102];
int visited[102][102];

void dfs(int i, int j, int n)
{
    visited[i][j] = 1;

    int x, y;
    for (int a = 0; a < 8; a++)
    {
        x = i + dr[a];
        y = j + dc[a];

        if (x >= 0 and y >= 0 and x < n and y < n and !visited[x][y])
        {
            if (grid[x][y] == 'x' or grid[x][y] == '@')
                dfs(x, y, n);
        }
    }
}

int32_t main()
{
    fastio;
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];

        memset(visited, 0, sizeof(visited));
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 'x' and !visited[i][j])
                {
                    ans++;
                    dfs(i,j,n);
                }
            }

        printf("Case %d: %d\n", t, ans);
    }
}