// AVOID PITFALLS
// Use long long int
// Use 10**18 to initialize dist array .Don't go for INT_MAX
// there can be more than one road b/w two cities enter minimum length in your intitial dist matrix

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
#define ii pair<int, int>

int dist[502][502];

void floyd(int v)
{
    int i, j, k;
    for (k = 1; k <= v; k++)
    {
        for (i = 1; i <= v; i++)
            for (j = 1; j <= v; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
    }
}

int32_t main()
{
    int n, m, q, a, b, c, i, j;
    cin >> n >> m >> q;
    for (i = 0; i < 502; i++)
        for (j = 0; j < 502; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = 100000000000000000;
        }
    // memset(dist,INT64_MAX,sizeof(dist));
    for (i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        dist[a][b] = min(c, dist[a][b]);
        dist[b][a] = dist[a][b];
    }

    floyd(n);

    for (i = 0; i < q; i++)
    {
        cin >> a >> b;
        if (dist[a][b] == 100000000000000000)
            cout << "-1\n";
        else
            cout << dist[a][b] << '\n';
    }

    return 0;
}
