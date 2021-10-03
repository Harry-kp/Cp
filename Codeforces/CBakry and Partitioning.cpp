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

const int N = 1e5 + 5;
vector<int> adj[N];
int val[N], xor_arr[N];
bool vis[N];
int cnt = 0;

int dfs1(int u)
{
    xor_arr[u] = val[u];
    vis[u] = true;

    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            xor_arr[u] ^= dfs1(v);
        }
    }
    return xor_arr[u];
}

int dfs2(int u)
{
    vis[u] = true;
    int tmp = val[u];
    for (auto v : adj[u])
    {
        if (!vis[v])
            tmp ^= dfs2(v);

        if (tmp == xor_arr[0])
        {
            tmp = 0;
            cnt++;
        }
    }
    return tmp;
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
        int n, k, u, v;
        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
            vis[i] = false;
        }

        for (int i = 0; i < n - 1; i++)
        {
            cin >> u >> v;
            u--;
            v--;
            adj[u].EB(v);
            adj[v].EB(u);
        }

        dfs1(0);
        for (int i = 0; i < n; i++)
        {
            vis[i] = false;
        }
        bool ans = false;
        if (xor_arr[0] == 0)
        {
            ans = true;
        }
        else
        {
            dfs2(0);
            if (cnt >= 2 and k != 2)
            {
                ans = true;
            }
        }
        cout << (ans ? "YES" : "NO") << '\n';
        cnt =0 ;
        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
            xor_arr[i] = val[i] = 0;
        }
    }
}
