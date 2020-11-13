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

int nice_swap(int n,int& sum1){
    // cout<<sum1<<endl;
    int ans = 0,l = 0,r = 0,i;
    for(i = 1;i<n;i++){
        l = (i*(i+1))/2;
        r = sum1-l;
        // cout<<l<<"---"<<r<<endl;
        if(r-l<0){break;}
        else{
            if(r-l == 0){
                ans += (i*i + (n - i)*(n - i) - n)/2;
                // debug1;
            }
        
            else{
                // debug2;
                int di = (r-l)/2;
                if((n-di)>=0 and (n-di)<=i){
                    // debug2;
                    ans+=n-di;}
            }
        }
    }
        

return ans;
}


int32_t main(){
    fastio ;
    int t;
    cin>>t;
    while(t--){
        int n;
        int sum1 = 0;
        cin>>n;
        sum1 = (n*(n+1))/2;
        if(sum1&1 == 1)cout<<0<<endl;
        else{
            cout<<nice_swap(n,sum1)<<endl;
        }
    }
    }
