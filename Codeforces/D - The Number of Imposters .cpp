#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
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
int binExp(int a, int b, int m){int r = 1;while (b){if (b % 2 == 1)r = (r * a) % m;a = (a * a) % m;b = b / 2;}return r;}

const int N = 2*1e5 + 5;
int cnt[2];
bool contra;

vector<pair<int,int>> adj[N];
int color[N];

void dfs(int u){
    // count colors of 0 and 1
    cnt[color[u]]++;
    // for each edge from u :edge = {v,dist}
    for(auto v:adj[u]){
        // if this node is not visited
        if(color[v.F] == -1){
            // then the child color will be 
            //different from parent if it is "IMPOSTER STATEMENT"
            // same as parent if it is "CREWMATE STATEMENT"
            // the edge weight told you which statement it is
            // 0 - crewmate,1- imposter
            // Hence, xor can do this work efficiently
            color[v.F]=color[u]^v.S;
            dfs(v.F);
        }
        else if (color[v.F] != (color[u] ^ v.S))  //contradiction
            contra = true;
    }
}

int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n,m,u,v;
        string st;
        cin>>n>>m;
        
        for(int i = 0;i<n;i++){
            color[i] = -1;
            adj[i].clear();
        }

        for(int i = 0;i<m;i++){
            cin>>u>>v>>st;
            u--;v--;

            if (st == "imposter")
            {
                adj[u].push_back({v,1});
                adj[v].push_back({u, 1});
            }
            else
            {
                adj[u].push_back({v, 0});
                adj[v].push_back({u, 0});
            }
        }

        int ans = 0;
        contra = false;
        for(int i = 0;i<n;i++){
            if(color[i] == -1){
                cnt[0] = cnt[1] = 0;
                color[i] = 0;
                dfs(i);
                ans += max(cnt[0],cnt[1]);
            }
        }

        cout<<(contra?-1:ans)<<'\n';
        
        
    }
}
