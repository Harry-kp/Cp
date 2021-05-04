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

int visited[100005];

void dfs(int v, vector<int> list[], int &c)
{
    visited[v] = 1;
    for (int x : list[v])
    {
        if (!visited[x])
        {
            c++;
            dfs(x, list, c);
        }
    }
}

int32_t main()
{
    fastio;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        memset(visited, 0, sizeof(visited));
        int n, p, i, u, v;
        cin >> n >> p;

        vector<int> list[n + 2];
        for (i = 0; i < p; i++)
        {
            cin >> u >> v;
            list[u].emplace_back(v);
            list[v].emplace_back(u);
        }
        int c;
        vector<int> country;
        for (i = 0; i <n; i++)
        {
            if (!visited[i])
            {
                c = 1;
                dfs(i, list, c);
                country.emplace_back(c);
            }
        }
        vector<int> prefix_sum = country;

        for (i = 1; i < prefix_sum.size(); i++)
            prefix_sum[i] += prefix_sum[i - 1];

        int ans = 0;
        for (i = country.size() - 1; i >= 1; i--)
            ans += (country[i] * prefix_sum[i - 1]);
        cout << ans << '\n';
    }
}
