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


int sum_13(int n){
    int tmp = (n*(n+1))/2;
    return tmp;
}

int sum2(int n){
    int tmp = (n*(n+1)*(2*n+1))/6;
    return tmp;
}

void solve1(int n){
    int sum1 = sum_13(n);
    if(sum1&1)cout<<'0'<<endl
}
int32_t main(){
    fastio ;
    int t,k;
    cin>>k>>t;
    while(t--){
        int n,i;
        cin>>n;
        string ans(n,'0');
        // cout<<ans<<endl;
        
        int sum1,half;
        sum1 = asum(n);
        if(sum1&1){half = (sum1+1)/2;cout<<'1'<<endl;}
        else {half = sum1/2;cout<<'0'<<endl;}
        i = n;
        half = sum1/2;
        while(i>0 and half>0){
            // cout<<"tmp"<<tmp<<endl;
            if(i<=half){
                ans[i-1]='1';
                half-=i;
            }
            else ans[i-1]='0';
            i--;
        }
        cout<<ans<<endl;


        
    }
    // cout<<s<<endl;
}