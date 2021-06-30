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
int dp[10004][10004];

int solve(int n,int m){

    if(dp[1][1] == -1)
        return 0;
    dp[1][1] = 1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(dp[i][j] == -1)
                dp[i][j] = 0;
            else{
                if(i>1)
                    dp[i][j] = dp[i-1][j];
                if(j>1)
                    dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
            }
        }
    }
    return dp[n][m];
}

int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n,m,p,x,y;

        cin>>n>>m>>p;
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<p;i++){
            cin>>x>>y;
            dp[x][y] = -1;
        }

        cout<<solve( n, m)<<'\n';
    }


}
