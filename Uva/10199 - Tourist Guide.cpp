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

map<int, string> indexCity;
map<string, int> cityIndex;

const int N = 105;
vector<int> adj[N];
set<string> camera;
int visited[N], dis[N], low[N];
int cnt;
void IS_AP(int cam)
{
    camera.insert(indexCity[cam]);
}

void dfs(int s, int p = -1)
{
    int child = 0;
    visited[s] = 1;
    dis[s] = low[s] = cnt++;

    for (auto v : adj[s])
    {
        if (v == p)
            continue;
        if (visited[v])

            low[s] = min(low[s], dis[v]);

        else
        {
            dfs(v, s);
            // update low for s from nodes in its dfs spanning tree
            low[s] = min(low[s], low[v]);
            // check AP
            if (low[v] >= dis[s] and p != -1)
            { //p!=-1 for exculding root
                IS_AP(s);
            }
            child++;
        }
    }
    // special case for root
    if (p == -1 and child > 1)
    {
        IS_AP(s);
    }
}

void findCamera(int n, int t)
{

    

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);

    cout << "City map #" << t << ": ";
    cout << camera.size() << " camera(s) found\n";
    // sort(camera.begin(), camera.end());
    for (auto x : camera)
    {
        cout << x << '\n';
    }
    // cout<<'\n';
}

int32_t main()
{
    fastio;
    int n, t = 0;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        if(t)cout<<'\n';
        
        // preprocessing
        cnt = 0;
        for (int i = 0; i < N; i++)
        {
            visited[i] = 0;
            dis[i] = -1;
            low[i] = -1;
            adj[i].clear();
        }
        indexCity.clear();
        cityIndex.clear();
        camera.clear();


        t++;
        string city, a, b;

        for (int i = 0; i < n; i++)
        {
            cin >> city;
            cityIndex.insert(MP(city, i));
            indexCity.insert(MP(i, city));
        }

        int m, x, y;
        cin >> m;

        

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            x = cityIndex[a];
            y = cityIndex[b];
            adj[x].EB(y);
            adj[y].EB(x);
        }

        

        findCamera(n, t);
        for(int i = 0;i<N;i++)
            adj[i].clear();
        // cout<<endl;
        
    }
}