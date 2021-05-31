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

int dp[100005][105];
int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, m, i, j;
        cin >> n >> m;
        int A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];

        if (A[0] == 0)
            fill(dp[0], dp[0] + 105, 1);
        else
        {
            dp[0][A[0]] = 1;
        }

        for (i = 1; i < n; i++)
        {
            if (A[i] == 0)
            {
                for (j = 1; j <= m; j++)
                {
                    dp[i][j] += dp[i - 1][j];
                    if (j - 1 > 0)
                        dp[i][j] += dp[i - 1][j - 1];
                    if (j + 1 <= m)
                        dp[i][j] += dp[i - 1][j + 1];
                    dp[i][j] %= MOD;
                }
            }
            else
            {
                dp[i][A[i]] += dp[i - 1][A[i]];
                if (A[i] - 1 > 0)
                    dp[i][A[i]] += dp[i - 1][A[i] - 1];
                if (A[i] + 1 <= m)
                    dp[i][A[i]] += dp[i - 1][A[i] + 1];
                dp[i][A[i]] %= MOD;
            }
        }

        int ans = 0;
        for (i = 1; i <= m; i++)
        {
            ans += dp[n - 1][i];
            ans %= MOD;
        }
        cout << ans << endl;
    }
}