
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

int fact[100001];


int binary(int a,int n){
    int res = 1;
    a = a%MOD;
    while(n>0){
        if(n&1)
            res = (res*a)%MOD;
        a = (a*a)%MOD;
        n>>=1;
    }
    return res;
}

int ncr(int n, int r){
    return (((fact[n] * binary(fact[r], MOD-2)) % MOD) * (binary(fact[n-r], MOD-2) % MOD)) % MOD;
}


int32_t main(){
    fastio ;

    fact[0] = 1; 
    for (int i = 1; i <=100000; i++) 
        fact[i] = (fact[i - 1] * i) % MOD; 

    int t;
    cin>>t;
    while(t--){
        int n,i,x,max1,c,ans = 0;
        cin>>n;
        max1 = -1;
        c = 1;
        for(i = 0;i<n;i++){
            cin>>x;
            
            if(max1 == x){
                c++;
            }
            else if(x>max1){
                c = 1;
                max1 = x;
            }
            
        }if(c%2 == 0){
            int minus = binary(2,n-c);
            minus = (minus *  ncr(c,c/2))%MOD;
            int ans = (binary(2,n) -  minus);
            if(ans<0)ans+=MOD;
            cout<<ans<<endl;

        }else
        cout<<(binary(2,n))<<endl;
    }
    // cout<<ncr(10000,1234)<<endl;
}