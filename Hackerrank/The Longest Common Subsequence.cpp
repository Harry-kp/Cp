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


int dp[1005][1005],s1[1005],s2[1005];

int solve(int n,int m){
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            if(i ==0 or j ==0 )
                dp[i][j] = 0;
            else{
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    return dp[n][m];
}
int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> s1[i];
        for (int i = 0; i < m; i++)
            cin >> s2[i];
        
        int len = solve(n,m);
        int lcs[len+1];
        lcs[len] = '\0';

        int i = n,j = m,ind = len-1;
        while(i>0 and j>0){
            if(s1[i-1] == s2[j-1]){
                lcs[ind] = s1[i-1];
                i--;j--;ind--;
            }else{
                if(dp[i-1][j]>dp[i][j-1])
                    i--;
                else
                    j--;
            }
        }

        for(int i = 0;i<len;i++)
            cout<<lcs[i]<<" ";
    }
}
