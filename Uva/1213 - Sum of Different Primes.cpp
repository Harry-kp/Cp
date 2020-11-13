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

vector<int> prime ;
bool is_prime[1121];

int dp[1121][15];


void sieve(){
    int i,j;
    memset(is_prime,true,sizeof(is_prime));
    for(i = 2;i*i<=1120;++i)
        if(is_prime[i]){
            for(j = i*i;j<=1120;j+=i)
                is_prime[j] = false;
        }
    // prime.EB(0);
    for(i = 2;i<=1120;++i)
        if(is_prime[i])prime.EB(i);
}


void solve () {
    sieve();
    // cout<<prime.size()<<endl;
    memset(dp,0,sizeof(dp));
    int N,K,id,n,k;
    dp[0][0] = 1;
    for(id = 0;id<prime.size();++id)
        for(n = 1120;n>=prime[id];n--)
            for(k = 1;k<=14;k++)
                dp[n][k]+=dp[n-prime[id]][k-1];
    while(cin>>N>>K && N){
        cout<<dp[N][K]<<endl;
    }
    
}


int32_t main(){
    fastio ;
    // int t,tt = 1 ;
    // cin>>tt;
    // for( t = 0 ;t<tt;++t ){
        solve() ;
    // }

}