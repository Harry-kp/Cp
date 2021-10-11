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


int dr[] = {0,-1,0,1,-1,-1,1,1};
int dc[] = {-1,0,1,0,-1,1,1,-1};


// Maths Utils
int binExp(int a, int b, int m){int r = 1;while (b){if (b % 2 == 1)r = (r * a) % m;a = (a * a) % m;b = b / 2;}return r;}



int A[2][105],vis[2][105];

void dfs(int i,int j,int n){
    if(i>=0 and j>=0 and i<2 and j<n and A[i][j] == 1 and !vis[i][j]){
        vis[i][j] = true;
        for(int c = 0;c<8;c++)
            dfs(i+dr[c],j+dc[c],n);
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
        int n;
        cin>>n;
        string s;
        for(int i = 0;i<2;i++){
            cin>>s;
        for(int j = 0;j<n;j++){
            A[i][j] = (s[j] == '0');
            vis[i][j] = false;
        }
        }
        
        dfs(0,0,n);
        cout<<(vis[1][n-1]?"YES":"NO")<<'\n';
        
    }
}
