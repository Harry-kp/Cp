#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define int long long int 

string a,b;
int dp[1005][1005];


int solve(int posa,int posb,int o)
{
    int n = a.size();
    if(posa>=n and posb>=n)
        return 0;
    
    if(dp[posa][posb]!=-1)return dp[posa][posb];

    int ans = INT64_MAX;

    if(posa<n)
        ans = min(ans,o*(a[posa] == '0') + solve(posa+1,posb,o + (a[posa] == '1')));
    if(posb<n)
        ans = min(ans,o*(b[posb] == '0') + solve(posa,posb+1,o + (b[posb] == '1')));
    
    return dp[posa][posb]= ans;
}

int inversion(){
    int n;
    cin>>n;
    cin>>a>>b;
    memset(dp,-1,sizeof dp);
    return solve(0,0,0);
}
int32_t main()
{
   
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        cout<<inversion()<<'\n';
    }
}
