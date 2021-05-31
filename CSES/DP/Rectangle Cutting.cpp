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
        int n, m, i, j;
        cin >> n >> m;
        int dp[n + 1][m + 1];
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                dp[i][j] = 1000000000;
            }
        }

        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                if (i == j)
                    dp[i][j] = 0;
                else if (i == 1 or j == 1)
                    dp[i][j] = max(i, j) - 1;
                else
                {
                    int row = i / 2;
                    int col = j / 2;
                    for (int k = 1; k <= row; k++)
                    {
                        dp[i][j] = min(1 + dp[i - k][j] + dp[k][j], dp[i][j]);
                    }
                    for (int k = 1; k <= col; k++)
                    {
                        dp[i][j] = min(1 + dp[i][j - k] + dp[i][k], dp[i][j]);
                    }
                }
            }
        }
        cout << dp[n][m];
    }
}