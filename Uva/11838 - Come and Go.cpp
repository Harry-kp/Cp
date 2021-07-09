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
int binExp(int a, int b, int m){int r = 1;while (b){if (b % 2 == 1)r = (r * a) % m;a = (a * a) % m;b = b / 2;}return r;}

int ans,cnt;
int visited[2005],dist[2005],low[2005];
vector<int> adj[2005];
stack<int> st;

void tarjan(int u){
    visited[u] = 1;
    dist[u] = low[u] = cnt++;

    st.push(u);

    for(auto v:adj[u]){
        if(!visited[v]){
            tarjan(v);
            low[u] = min(low[u],low[v]);

        }else if(visited[v] == 1){
            low[u] = min(low[u],dist[v]);
        }
    }

    if(dist[u] == low[u]){
        ans++;
        int x;
        while(st.top()!=u){
            x = st.top();
            visited[x] = 2;
            low[x] = dist[u];
            st.pop();
        }
        st.pop();
        visited[u] = 2;
    }
}


int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int n,m;
    while (1)
    {
        cin>>n>>m;

        if(n == 0)break;

        // pre-process
        for(int i = 1;i<2005;i++){
            adj[i].clear();
            low[i] = dist[i] = -1;
            visited[i] = 0;
        }
        ans = 0;
        cnt = 0;

        int a,b,p;
        for(int i = 0;i<m;i++){
            cin>>a>>b>>p;

            adj[a].EB(b);
            if(p == 2)adj[b].EB(a);
        }

        for(int i  = 1;i<=n;i++)
            if(!visited[i])
                tarjan(i);
        // cout<<ans<<'\n';
        if(ans == 1)
            cout<<1<<'\n';
        else cout<<0<<'\n';
    }
}