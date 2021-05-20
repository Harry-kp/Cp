// AVOID PITFALLS
// Use long long int
// priority queue in c++ is max heap  (I am python programmar so i think its min heap like  in python and got few tc right and then after hours of search i found this.)
// Use 10**18 or INT64_MAX to initialize dist array .Don't go for INT_MAX
// see line 58





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

int dist[100005];
vector<ii> adj[100005];
priority_queue<ii> pq;

void relax(int node)
{
    for (auto x : adj[node])
    {
        if (dist[x.F] > dist[node] + x.S)
        {
            dist[x.F] = dist[node] + x.S;
            pq.push(MP(-dist[x.F],x.F));
        }
    }
}

void dj(int src)
{
    dist[src] = 0;
    pq.push(MP(0, src));
    ii best_node;
    while (!pq.empty())
    {
        best_node = pq.top();
        pq.pop();
        if(-best_node.F<=dist[best_node.S])  //==this line is imp else TLE in last two cases
            relax(best_node.S);
    }
}

int32_t main()
{
    fastio;
    int n, m, a, b, c, i;
    cin >> n >> m;
    for(int i = 1;i<100005;i++)dist[i] = INT64_MAX;
    for ( i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].EB(MP(b, c));
    }
    dj(1);

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
}