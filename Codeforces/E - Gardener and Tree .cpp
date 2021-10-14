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

struct dsu
{

    vector<int> parent, size;
    void init(int n)
    {
        parent.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = i;
        }
    }

    int find(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    void union_set(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

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
        vector<int> adj[n];
        for (int i = 0; i < n - 1; i++)
        {
            cin >> u >> v;
            u--, v--;
            adj[v].EB(u);
            adj[u].EB(v);
        }

        // the time when a node is pruned is equal to second largest prune time among all its neighbours + 1

        // the solution can be simulated as topological sort

        vector<int> deg(n), dep(n);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            deg[i] = adj[i].size();
            dep[i] = 1;

            if (deg[i] == 1)
            {
                q.push(i);
    
            }
        }

        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (auto v : adj[x])
            {
                // already visited
                if (deg[v] <=1)
                    continue;
                
                dep[v] = max(dep[v],1+dep[x]);
                deg[v]--;
                if(deg[v] == 1)
                    q.push(v);
            }
        }
        int ans =0;
        for(int i = 0;i<n;i++){
            if(dep[i]>k)
                ans++;
        }
        cout<<ans<<'\n';
    }
}
