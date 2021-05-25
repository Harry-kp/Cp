
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

void solve()
{
    int n, a, b;
    cin >> n;

    int node[n + 1][2];
    vector<int> adj[n + 1];
    int dp[n + 1][2]; //0 == l 1 == r

    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        node[i][0] = a;
        node[i][1] = b;
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adj[a].EB(b);
        adj[b].EB(a);
    }

    function<void(int, int)> dfs;

    dfs = [&](int s, int p) {
        // visited[s] = 1;

        dp[s][0] = dp[s][1] = 0;
        for (auto x : adj[s])
        {
            if (x == p)
                continue;

            dfs(x, s);

            dp[s][0] += max(dp[x][0] + abs(node[x][0] - node[s][0]),
                            dp[x][1] + abs(node[x][1] - node[s][0]));

            dp[s][1] += max(dp[x][0] + abs(node[x][0] - node[s][1]),
                            dp[x][1] + abs(node[x][1] - node[s][1]));
        }

        // if (adj[s].size() == 1)
        // {
        //     dp[s][0] = dp[s][1] = 0;
        // }
    };
    dfs(1, -1);
    cout << max(dp[1][0], dp[1][1]) << endl;
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}