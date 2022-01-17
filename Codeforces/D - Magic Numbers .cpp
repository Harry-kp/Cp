#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define int long long int
const int MOD = 1e9+7;  

string a,b;
int dp[2000][2000][2][2];

int solve(int pos,int cur,int t1,int t2,int m,int d){
    if(pos == a.size()){
        return (cur==0);
    }
    if(dp[pos][cur][t1][t2]!=-1)return dp[pos][cur][t1][t2];
    int ans = 0;
    int lb = t1?a[pos]-'0':0;
    int ub = t2?b[pos]-'0':9;

    if((pos+1)%2 == 0){
        if(d>=lb and d<=ub)
        ans = (ans + solve(pos+1,(cur * 10 + d)%m,t1&(lb == d),t2&(ub == d),m,d))%MOD;
    }else{
        for(int j = lb;j<=ub;j++){
            if(j!=d)
            ans = (ans + solve(pos+1,(cur * 10 + j)%m,t1&(j == lb),t2&(j==ub),m,d))%MOD;
        }
    }
    return dp[pos][cur][t1][t2] = ans;
}

int32_t main()
{
    
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int m,d;
        cin>>m>>d;
        cin>>a>>b;
        memset(dp,-1,sizeof dp);
        cout<<solve(0,0,1,1,m,d)<<'\n';

    }
}
