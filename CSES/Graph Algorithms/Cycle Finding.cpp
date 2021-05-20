#include <bits/stdc++.h>

#define int long long int
using namespace std;

struct edge
{
    int src;
    int dest;
    int cost;
};

struct Graph
{

    int V;
    vector<edge> Edges;
    vector<int> parent;
    vector<int> dist;
    Graph(int ver)
    {
        V = ver;
        parent.resize(V + 1, -1);
        dist.resize(V + 1, 1000000000000000);
    }

    void addEdge(struct edge e)
    {
        Edges.emplace_back(e);
    }

    void bellman()
    {
        int tmp;
        dist[1] = 0;
        for (int i = 1; i <= V; i++)
        {
            tmp = -1;
            for (auto x : Edges)
            {
                if (dist[x.dest] > dist[x.src] + x.cost)
                {
                    tmp = x.src;
                    parent[x.dest] = x.src;
                    dist[x.dest] = dist[x.src] + x.cost;
                }
            }
        }
        if (tmp == -1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            for (int i = 1; i <= V; i++)
            {
                tmp = parent[tmp];
            }

            vector<int> ans;
            ans.emplace_back(tmp);
            int tmp2 = tmp;

            do
            {
                tmp2 = parent[tmp2];
                ans.emplace_back(tmp2);
            } while (tmp2 != tmp);

            reverse(ans.begin(), ans.end());

            for (auto x : ans)
            {
                cout << x << " ";
            }
            cout << '\n';
        }
    }
};

int32_t main()
{
    int t;
    t = 1;
    while (t--)
    {
        int n, m, a, b, c, i;
        cin >> n >> m;
        Graph g(n);
        for (i = 1; i <= m; i++)
        {
            struct edge e1;
            cin>>e1.src>>e1.dest>>e1.cost;
            g.addEdge(e1);
        }

        g.bellman();
    }
}
