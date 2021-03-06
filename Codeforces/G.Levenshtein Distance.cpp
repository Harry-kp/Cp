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

int cost(char a,char b){
    if(a == b)return 0;
    return abs(a-b);
}


int32_t main(){
    string a,b;
    cin>>a>>b;
    // cout<<a<<'\n'<<b;
    int i,j,na,nb;
    
    na = a.size();
    nb = b.size();
    
    int dp[na+1][nb+1];
    
    dp[0][0] = 0;
    
    for(i  = 1;i<=na;i++){
        dp[i][0] = dp[i-1][0] + a[i-1]-96;
    }
    
    for(j  = 1;i<=nb;i++){
        dp[0][j] = dp[0][j-1] + b[j-1]-96;}
    
    for(i = 1;i<=na;i++)
        for(j = 1;j<=nb;j++)
            dp[i][j] = min(min(dp[i-1][j] + a[i-1]-96,dp[i][j-1] + b[j-1]-96),dp[i-1][j-1] + cost(a[i-1],b[j-1]));
    cout<<dp[na][nb];
            
    
    
}