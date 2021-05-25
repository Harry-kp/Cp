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
        int n, x, min1;
        cin >> n >> x;
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];

        int dp[x];
        dp[0] = 0;
        for (int i = 1; i <= x; i++)
        {
            dp[i] = 1000000000;
            min1 = 1000000000;
            for (int j = 0; j < n; j++)
            {
                if (i - A[j] >= 0)
                    dp[i] = min(dp[i], dp[i - A[j]]);
            }
            dp[i]++;
        }
        if (dp[x] > x)
            cout << -1 << '\n';
        else
            cout << dp[x] << '\n';
    }
}