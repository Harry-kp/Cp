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
        int n, m, i, j;
        string w1, w2;
        cin >> w1 >> w2;

        n = w1.size();
        m = w2.size();
        int dp[n + 1][m + 1];

        memset(dp, 0, sizeof(dp));

        for (i = 0; i <= n; i++)
            for (j = 0; j <= m; j++)
            {
                if (i == 0 or j == 0)
                    dp[i][j] = max(i, j);
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1] + (w1[i - 1] != w2[j - 1]), 1 + min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        
        cout<<dp[n][m];
    }
}