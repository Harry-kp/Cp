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
        int tot = (n * (n + 1)) / 2;

        if (tot % 2 == 1)
        {
            cout << "0\n";
            return 0;
        }

        tot = tot / 2;

        vector<vector<int>> dp(n, vector<int>(tot + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= tot; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - i >= 0)
                    dp[i][j] += dp[i - 1][j - i];
                if (dp[i][j] > MOD)
                    dp[i][j] -= MOD;
            }
        }
        cout << dp[n - 1][tot] << '\n';
    }
}