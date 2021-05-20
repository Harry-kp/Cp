#include <bits/stdc++.h>
#define int long long int

using namespace std;

struct Graph
{
    int V;
    vector<vector<int>> adj;
    vector<int> inDegree;
    vector<vector<int>> dp;
    string letter;
    Graph(int vert, string let)
    {
        V = vert;
        letter = let;
        adj.resize(V + 1);
        inDegree.assign(V + 1, 0);
        dp.resize(V + 1, vector<int>(26, 0));
    }

    void addedge(int u, int v)
    {
        adj[u].emplace_back(v);
        inDegree[v]++;
    }

    int topologicalSort()
    {
        int ans = 0;
        int cnt = 0;
        queue<int> Q;

        for (int i = 1; i <= V; i++)
        {
            if (inDegree[i] == 0)
            {
                Q.push(i);
                dp[i][letter[i - 1] - 'a'] = 1;
            }
        }

        int tmp;
        while (!Q.empty())
        {
            tmp = Q.front();
            // ans.emplace_back(tmp);
            Q.pop();

            for (auto x : adj[tmp])
            {
                for (int i = 0; i < 26; i++)
                    dp[x][i] = max(dp[tmp][i] + (letter[x - 1] - 'a' == i), dp[x][i]);

                inDegree[x]--;
                if (inDegree[x] == 0)
                {
                    Q.push(x);
                }
            }
            cnt++;
        }

        if (cnt != V)
            return -1;

        for (int i = 1; i <= V; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                ans = max(dp[i][j], ans);
            }
        }
        return ans;
    }
};

int32_t main()
{
    int t = 1;
    while (t--)
    {
        int n, m, a, b;
        string s;
        cin >> n >> m;
        cin >> s;
        Graph G(n, s);

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            G.addedge(a, b);
        }
        cout << G.topologicalSort() << '\n';
    }
}