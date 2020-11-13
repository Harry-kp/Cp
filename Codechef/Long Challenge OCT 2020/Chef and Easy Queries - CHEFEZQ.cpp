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


int arr[100001];

int32_t main(){
    fastio ;
    int t;
    cin>>t;
    while(t--){
        int n,k,sum1 = 0,tmp,i,ans = -1,sum2 = 0;
        cin>>n>>k;
        for(i  = 0;i<n;i++)
            {
                cin>>arr[i];
                sum1+=arr[i];
            }
        for(i  = 1;i<=n;i++){
            sum2+=arr[i-1];
            if(sum2<k){ans = i;break;}
            sum2-=k;
        }
        if(ans == -1){ans = sum1/k+1;}
        cout<<ans<<endl;
            
    }
}