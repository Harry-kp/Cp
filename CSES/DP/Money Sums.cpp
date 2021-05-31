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
        int n, i, j, sum1 = 0;
        cin >> n;
        int A[n];

        for (i = 0; i < n; i++)
        {
            cin >> A[i];
            sum1 += A[i];
        }

        int dp[n + 1][sum1 + 1];
        memset(dp, 0, sizeof(dp));

        for (i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= sum1; j++)
            {
                if (j - A[i - 1] >= 0)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        int ans = 0;
        for (i = 1; i <= sum1; i++)
            ans += dp[n][i];

        cout << ans << '\n';
        for (i = 1; i <= sum1; i++)
        {
            if (dp[n][i])
                cout << i << " ";
        }
    }
}