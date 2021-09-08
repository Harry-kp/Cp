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
// #define int long long int
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

int n, m;
char grid[105][105];
int dp[105][105][105][105];
int dx1[] = {1, 1, 0, 0};
int dy1[] = {0, 0, 1, 1};
int dx2[] = {1, 0, 1, 0};
int dy2[] = {0, 1, 0, 1};

int solve(int x1, int y1, int x2, int y2)
{
    if (dp[x1][y1][x2][y2] != -1)
        return dp[x1][y1][x2][y2];

    if (x1 >= n or y1 >= m or x2 >= n or y2 >= m or grid[x1][y1] == '#' or grid[x2][y2] == '#')
        return INT_MIN;
    if (x1 == n - 1 and y1 == m - 1)
        return (grid[x1][y1] == '*');
    int ans = INT_MIN;
    for (int i = 0; i < 4; i++)
    {
        ans = max(ans, solve(x1 + dx1[i], y1 + dy1[i], x2 + dx2[i], y2 + dy2[i]));
    }
    ans += (grid[x1][y1] == '*') + (grid[x2][y2] == '*') - (x1 == x2 and y1 == y2 and grid[x1][y1] == '*');
    return dp[x1][y1][x2][y2] = ans;
}

int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {

        cin >> m >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];

        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0, 0, 0) << '\n';
    }
}
