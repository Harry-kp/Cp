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
// %[flags][width][.precision][length]specifier 


int dp[300005][13];


int32_t main(){
    fastio ;
    memset(dp,0,sizeof(dp));
    int num ,i,j;
    float tmp;
    int arr[] = {10000,5000,2000,1000,500,200,100,50,20,10,5};

    for(i = 0;i<11;i++)dp[0][i] = 1;

    for(i = 1;i<=300003;i++)
        for(j = 0;j<11;j++){
            int x,y;

            x = (i-arr[j]>=0) ? dp[i-arr[j]][j]:0;
            y = (j>=1)?dp[i][j-1]:0;
            dp[i][j] = x+y;
        }

    while(cin>>tmp){
        if(tmp == 0.00)break;
        num = (int)(tmp*100);
        printf("%6.2f%17lld\n",tmp,dp[num][10]);
        // cout<<dp[num][10]<<endl;
    }
    forward_list<int> a;
    a.insert_after();
}