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

int dp[32][1005];
void solve () {
    int i,j,n,w,t,o = 0;
    cin>>t;

    
    while(true){
    cin>>w;
    cin>>n;
    int D[n],V[n];
    memset(dp,0,sizeof(dp));

    for(i = 0;i<n;i++){
        cin>>D[i];

        cin>>V[i];
    }
    for(i = 1;i<=n;i++)
        for(j = 1;j<=t;++j)
            {
                if(3*w*D[i-1]>j)
                    {dp[i][j] = dp[i-1][j];
                    }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-3*w*D[i-1]]+V[i-1]);

                }
            }
        int t1 = t;
        cout<<dp[n][t]<<endl;
        stack<int> s1;
        int res = dp[n][t];
        for(i = n;i>0 and res>0 ;i--){
            if(res == dp[i-1][t1])
                continue;
            else{
                s1.push(i-1);
                res-= V[i-1];
                t1 -= 3*w*D[i-1];
            }
        }
        cout<<s1.size()<<endl;
        while(!s1.empty())
            {
                int tmp = s1.top();
                s1.pop();
                cout<<D[tmp]<<" "<<V[tmp]<<endl;
            }
        if(cin>>t)cout<<endl;
        else break;


    }
}


int32_t main(){
    
    fastio ;
    
        solve() ;


}