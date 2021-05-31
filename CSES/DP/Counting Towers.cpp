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

int dp[1000001][2];
int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    //                                                 _____
    dp[1][0] = 1; //cell having centre border present |__|__|
    //                                                      _____
    dp[1][1] = 1; //cell having centre border not present  |_____|
    // when we proceed further i.e n = 2 four cases will arise
    // CASE 1 :: border present - border present
    // CASE 2 :: border present - border absent
    // CASE 3 :: border absent - border present
    // CASE 4 :: border absent - boder absent

    for (int i = 2; i <= 1000000; i++)
    {
        dp[i][0] = (dp[i][0] + 4 * dp[i - 1][0]) % MOD;
        dp[i][0] = (dp[i][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
        dp[i][1] = (dp[i][1] + 2 * dp[i - 1][1]) % MOD;
    }
    while (t--)
    {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
    }
}