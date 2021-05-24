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

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

vector<pair<int, int>> adjlist[100000 + 5];
int dist[100005][10];

void dj(int src, int k)
{
    pq.push({0, src});

    pair<int, int> node;
    while (!pq.empty())
    {
        node = pq.top();
        pq.pop();

        int u, d;
        u = node.S;
        d = node.F;

        if (dist[u][k - 1] < d)
            continue;
        for (auto child : adjlist[u])
        {
            int v, c;
            v = child.F;
            c = child.S;

            if (dist[v][k - 1] > d + c)
            {
                dist[v][k - 1] = c + d;
                pq.push({dist[v][k - 1], v});
                sort(dist[v], dist[v] + k);
            }
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
        int n, m, k, a, b, c, i, j;
        cin >> n >> m >> k;

        for (i = 0; i <= n; i++)
        {
            for (j = 0; j < 10; j++)
                dist[i][j] = 10000000000000000;
        }

        for (i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            adjlist[a].EB(MP(b, c));
        }

        dj(1, k);

        for (i = 0; i < k; i++)
            cout << dist[n][i] << " ";
    }
}