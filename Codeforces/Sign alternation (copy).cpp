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
#define FOR(var, len) for (var = 0; var < len; var++)
#define debug1 cout << "debug1" << '\n'
#define debug2 cout << "debug2" << '\n'
#define debug3 cout << "debug3" << '\n'

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
string s;
int dp[20][5][2];
int solve(int pos, int cnt, int tight)
{
    if (dp[pos][cnt][tight] != -1)
        return dp[pos][cnt][tight];
    if (s.size() == pos)
    {
        return 1;
    }
    int ans = 0;
    int j;
    if (tight)
        j = s[pos] - '0';
    else
        j = 9;

    for (int i = 0; i <= j; i++)
    {
        int cnt_up = cnt + (i > 0);
        if (cnt_up <= 3)
            ans += solve(pos + 1, cnt + (i > 0), tight & ((s[pos] - '0') == i));
    }
    return dp[pos][cnt][tight] = ans;
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        // L
        memset(dp, -1, sizeof dp);
        s = to_string(l - 1);
        int y = solve(0, 0, 1);

	//R
        memset(dp, -1, sizeof dp);
        s = to_string(r);
        int x = solve(0, 0, 1);
        cout << x - y << '\n';
    }
}
