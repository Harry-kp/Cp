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
// #define int long long
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
        int n, tot;
        cin >> n >> tot;
        // cout<<tot<<endl;
        int cost[n + 1], page[n + 1];

        for (int i = 1; i <= n; i++)
        {
            cin >> cost[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> page[i];
        }

        int dp[tot + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++)
        {
            for (int j = tot; j>=cost[i]; j--)
            {
                dp[j] = max(dp[j-cost[i]] + page[i],dp[j]);
            }
        }

        cout << dp[tot] << '\n';
    }
}