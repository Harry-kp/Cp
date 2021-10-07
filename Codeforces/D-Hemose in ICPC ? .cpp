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

const int N = 1e3 + 5;
vector<int> adj[N];
vector<int> euler;
bool vis[N];
int n;
// set<int>
void dfs(int u)
{
    vis[u] = true;
    euler.EB(u);
    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v);
            euler.EB(u);
        }
    }
}

void query(int l, int r)
{
    set<int> s;
    for (int i = l; i <= r; i++)
        s.insert(euler[i] + 1);
    cout << "?"
         << " " << s.size() << " ";
    for (auto it = s.begin(); it != s.end(); it++)
        cout << *it << " ";
    cout << '\n';
    cout.flush();

}

void print(int l, int r)
{
    cout << "! ";
    cout << l + 1 << " " << r + 1 << '\n';
    cout.flush();
}
void solve()
{
    int mx;
    query(0, euler.size() - 1);
    cin >> mx;
    int l = 0, r = euler.size() - 1, m, l1;

    while (r - l > 1)
    {
        m = (l + r) >> 1;
        query(l, m);
        cin >> l1;

        if (l1 == mx)
        {
            r = m;
        }
        else
            l = m;
    }
    print(euler[l], euler[r]);
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
        int u, v;
        cin >> n;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> u >> v;
            u--;
            v--;
            adj[u].EB(v);
            adj[v].EB(u);
        }

        for (int i = 0; i < n - 1; i++)
        {
            vis[i] = false;
        }
        dfs(0);
        solve();

        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
        }
        euler.clear();
    }
}
