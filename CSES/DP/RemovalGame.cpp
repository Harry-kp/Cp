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

int dp[5005][5005];

int solve(int i,int j,vector<int> &A){
    if(i>j)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    int st = A[i] + min(solve(i+2,j,A),solve(i+1,j-1,A));
    int ed = A[j] + min(solve(i,j-2,A),solve(i+1,j-1,A));

    return dp[i][j] = max(st,ed);
}

int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;cin>>n;
        vector<int> A(n);
        for(int i = 0;i<n;i++)cin>>A[i];
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,n-1,A)<<'\n';
    }
}