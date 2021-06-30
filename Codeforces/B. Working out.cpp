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

int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        // n++;c++;

        int cal[n + 1][m + 1];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> cal[i][j];
            }

        int dp1[n + 1][m + 1], dp2[n + 1][m + 1], dp3[n + 1][m + 1], dp4[n + 1][m + 1];

        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));
        memset(dp3, 0, sizeof(dp3));
        memset(dp4, 0, sizeof(dp4));

        // dp1 from source = 1,1 to N,M
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i > 1)
                    dp1[i][j] = max(dp1[i][j], dp1[i - 1][j]);
                if (j > 1)
                    dp1[i][j] = max(dp1[i][j], dp1[i][j - 1]);
                dp1[i][j] += cal[i][j];
            }
        }

        // dp2 from source = 1,m to n,1
        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 1; j--)
            {
                if (i > 1)
                    dp2[i][j] = max(dp2[i][j], dp2[i - 1][j]);
                if (j < m)
                    dp2[i][j] = max(dp2[i][j], dp2[i][j + 1]);
                dp2[i][j] += cal[i][j];
            }
        }

        // dp3 from source = n,1 to 1,M
        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i < n)
                    dp3[i][j] = max(dp3[i][j], dp3[i + 1][j]);
                if (j > 1)
                    dp3[i][j] = max(dp3[i][j], dp3[i][j - 1]);
                dp3[i][j] += cal[i][j];
            }
        }

        // dp4 from source = n,m to 1,1
        for (int i = n; i >= 1; i--)
        {
            for (int j = m; j >= 1; j--)
            {
                if (i < n)
                    dp4[i][j] = max(dp4[i][j], dp4[i + 1][j]);
                if (j < m)
                    dp4[i][j] = max(dp4[i][j], dp4[i][j + 1]);
                dp4[i][j] += cal[i][j];
            }
        }

        int max_cal[n + 1][m + 1];
        // solution starts here

        int mx = -10000000;
        for (int i = 2; i <= n - 1; i++)
            for (int j = 2; j <= m - 1; j++)
            {
                int case1 = dp1[i][j - 1] + dp3[i + 1][j] + dp2[i - 1][j] + dp4[i][j + 1];
                int case2 = dp1[i - 1][j] + dp3[i][j - 1] + dp4[i + 1][j] + dp2[i][j + 1];

                mx = max(mx, max(case1, case2));
            }
        cout << mx << '\n';
    }
}
