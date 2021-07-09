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
#define int long long int
#define S second
#define F first
#define FOR(var, len) for (var = 0; var < len; var++)
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

int scc, cnt;
int visited[100005], dist[100005], low[100005];
vector<int> adj[100005];
stack<int> st;

void tarjan(int u)
{
    visited[u] = 1;
    dist[u] = low[u] = cnt++;

    st.push(u);

    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (visited[v] == 1)
        {
            low[u] = min(low[u], dist[v]);
        }
    }

    if (dist[u] == low[u])
    {
        scc++;
        int x;
        while (1)
        {
            x = st.top();
            visited[x] = 2;
            dist[x] = scc;
            st.pop();
            if(x == u)
                break;
        }
    }
}

int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int n, m, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        // pre-process
        for (int i = 1; i < 100005; i++)
        {
            adj[i].clear();
            low[i] = dist[i] = -1;
            visited[i] = 0;
        }
        scc = 0;
        cnt = 0;

        int a, b, p;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].EB(b);
            // adj[b].EB(a);
        }

        for (int i = 1; i <= n; i++)
            if (!visited[i])
                tarjan(i);
        
        
        vector<int> degree(scc+1,0);
        for(int i = 1;i<=n;i++)
            for(auto v:adj[i]){
                if(dist[i]!=dist[v])
                    degree[dist[v]]++;
            }
        
        int ans = count(degree.begin()+1,degree.end(),0);
        cout<<ans<<'\n';
    }
}



