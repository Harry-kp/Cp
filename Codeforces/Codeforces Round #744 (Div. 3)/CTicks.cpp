#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define MP make_pair
#define EB emplace_back
#define MOD 1000000007
#define int long long int
#define S second
#define F first
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

// Brute force will do the job
// for every center check how long tick it can form and mark those cells
// at last check any given colored node is not marked
bool solve()
{
    int n, m, k;
    char x;
    cin >> n >> m >> k;

    int code[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            code[i][j] = (x == '*') ? 1 : 0;
        }

    int len;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (code[i][j] == 0)
                continue;
            len = 0;
            while (i - len - 1 >= 0 and j - len - 1 >= 0 and j + len + 1 < m and code[i - len - 1][j - len - 1] and code[i - len - 1][j + len + 1])
                len++;

            if (len >= k)
            {
                for (int d = 0; d <= len; d++)
                {
                    code[i - d][j - d] = 2;
                    code[i - d][j + d] = 2;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (code[i][j] == 1)
                return false;
    return true;
}

int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}
