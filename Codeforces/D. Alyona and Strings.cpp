#include <bits/stdc++.h>
using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);
#define PI(a, b) pair<a, b>
#define MP make_pair
#define EB emplace_back
#define MOD 1000000007
#define int long long int
#define S second
#define F first
#define FOR(var, len) for (var = 0; var < len; var++)
#define debug1 cout << "debug1" << '\n'
#define debug2 cout << "debug2" << '\n'
#define debug3 cout << "debug3" << '\n'

// int dr[] = {0,-1,0,1,-1,-1,1,1};
// int dc[] = {-1,0,1,0,-1,1,1,-1};

// Maths Utils
int binExp(int a, int b, int m)
{
    int r = 1;
    while (b)
    {
        if (b % 2 == 1)
            r = (r * a) % m;
        a = (a * a) % m;
        b = b / 2;
    }
    return r;
}

string s1, s2;
int n, m, k;
int dp[1005][1005][12][2];
int solve(int i, int j, int rem, int prev)
{
    if (i == n or j == m)
        return ((rem == k) ? 0 : INT_MIN);
    if (rem == k)
        return 0;

    if (dp[i][j][rem][prev] != -1)
        return dp[i][j][rem][prev];
    int ans = INT_MIN;
    if (prev == 1)
    {
        ans = max(ans, solve(i + 1, j, rem + 1, 0));
        ans = max(ans, solve(i, j + 1, rem + 1, 0));

        if (s1[i] == s2[j])
        {
            ans = max(ans, 1 + solve(i + 1, j + 1, rem, 1));
            ans = max(ans, 1 + solve(i + 1, j + 1, rem + 1, 0));
        }
    }
    else
    {
        ans = max(ans, solve(i + 1, j, rem, 0));
        ans = max(ans, solve(i, j + 1, rem, 0));

        if (s1[i] == s2[j])
        {
            ans = max(ans, 1 + solve(i + 1, j + 1, rem, 1));
            ans = max(ans, 1 + solve(i + 1, j + 1, rem + 1, 0));
        }
    }
    return dp[i][j][rem][prev] = ans;
}

int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        cin >> s1 >> s2;
        memset(dp, -1, sizeof dp);
        cout << solve(0, 0, 0, 0) << '\n';
    }
}
