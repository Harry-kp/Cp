#include <bits/stdc++.h>
using namespace std;
 
#define fastio           ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define PI(a,b)          pair<a,b>
#define MP               make_pair
#define EB               emplace_back
#define MOD              1000000007
#define int              long long
#define S                second
#define F                first
#define endl             '\n'
#define FOR(var,len)     for(var = 0;var<len;var++)
#define debug1           cout<<"debug1"<<'\n'
#define debug2           cout<<"debug2"<<'\n'
#define debug3           cout<<"debug3"<<'\n'
#define max_l            1000005

int dp[105][25005];
void solve () {
    int n,val = 0,i,j,val1;
    cin>>n;
    int ans[n+1];
    for(i = 1;i<=n;i++){
        cin>>ans[i];
        val+=ans[i];
    }
    val1 = val/2;
    memset(dp,0,sizeof(dp));
    for(i = 1;i<=n;i++)
        for(j = 1;j<=val1;j++){
            if(ans[i]<=j)
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-ans[i]]+ans[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    cout<<abs(val-2*dp[n][val1])<<'\n';


    
}


int32_t main(){
    fastio ;
    int t,tt = 1 ;
    cin>>tt;
    for( t = 0 ;t<tt;++t ){
        solve() ;
    }

}