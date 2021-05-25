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

int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char grid[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }

        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        // trivial cases
        if (grid[0][0] == '*' or grid[n - 1][n - 1] == '*')
            cout << 0 << '\n';
        else
        {   
            dp[0][0] = 1;

            // base conditions
            for (int i = 1; i < n; i++)
            {
                if(grid[0][i]!='*')
                    dp[0][i] = dp[0][i-1];
                if (grid[i][0] != '*')
                    dp[i][0] = dp[i-1][0];
            }

            // dp here
            for (int i = 1; i < n; i++)
            {
                for (int j = 1; j < n; j++)
                    if (grid[i][j] == '*')
                        dp[i][j] = 0;
                    else
                    {
                        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                        if (dp[i][j] >= MOD)
                            dp[i][j] -= MOD;
                    }
            }
            cout << dp[n - 1][n - 1] << '\n';
        }
    }
}