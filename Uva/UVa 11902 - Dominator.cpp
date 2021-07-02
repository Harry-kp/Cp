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

int adj[104][104];
vector<int> vis1, vis2;

void dfs(int s, int x, int n, int p)
{
    vis1[s] = 1;
    for (int i = 0; i < n; i++)
    {
        if (i != p and adj[s][i] == 1 and !vis1[i])
        {
            if (i != x)
                dfs(i, x, n, s);
        }
    }
}

void print_line(int n)
{
    cout << '+';
    for (int i = 1; i <= 2 * n - 1; i++)
        cout << '-';
    cout << "+\n";
}

int32_t main()
{
    fastio;
    int t = 1,tt = 0;
    cin >> t;

    while (t--)
    {   tt++;
        int n;
        cin >> n;
        char ans[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> adj[i][j];

        vis1.assign(n, 0);
        dfs(0, -1, n, -1);

        for (int i = 0; i < n; i++)
        {
            if (vis1[i])
                ans[0][i] = 'Y';
            else
                ans[0][i] = 'N';
        }

        vis2 = vis1;

        vis1.assign(n, 0);
        for (int i = 1; i < n; i++)
        {
            dfs(0, i, n, -1);
            for (int j = 0; j < n; j++)
            {
                if (vis2[j] and !vis1[j])
                    ans[i][j] = 'Y';
                else
                    ans[i][j] = 'N';
                vis1[j] = 0;
            }
        }

        // printing
        cout << "Case "<<tt<<":\n";
        print_line(n);
        for (int i = 0; i < n; i++)
        {
            cout<<'|';
            for (int j = 0; j < n; j++)
            {
                cout << ans[i][j] << "|";
            }
            cout << '\n';
            print_line(n);
        }
    }
}