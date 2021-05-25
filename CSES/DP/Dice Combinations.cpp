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
        int dp[n + 1];
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            dp[i] = 0;
            for (int j = 1; j <= 6; j++)
            {
                if (i - j >= 0)
                    dp[i] += dp[i - j];
                if (dp[i] >= MOD)
                    dp[i] -= MOD;
            }
        }
        cout << dp[n] << '\n';
    }
}