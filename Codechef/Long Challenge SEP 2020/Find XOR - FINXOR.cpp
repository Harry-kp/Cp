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
// #define endl             '\n'
#define FOR(var,len)     for(var = 0;var<len;var++)
#define debug1           cout<<"debug1"<<'\n'
#define debug2           cout<<"debug2"<<'\n'
#define debug3           cout<<"debug3"<<'\n'
#define max_l            1000005




int32_t main(){
    // freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    fastio ;
    int t;
    cin>>t;
    while(t--){
        int V[21];
        bitset<20> b1;
        int n,i,outcome;
        cin>>n;
        for(i = 1;i<=20;i++)
        {   int tmp = (1<<i) - 1;
            cout<<1<<" "<<tmp<<endl;
            cin>>V[i];
        }
        if(V[1]&1){
            if(n&1)b1[0]=0;
            else b1[0]=1;
            }
        else{
            if(n&1)b1[0] = 1;
            else b1[0] = 0;
        }

        for(i = 1;i<20;i++)
            {
                int c = (V[i+1]- V[i])/(1<<i);
                c = -1*c;
                int x1 = (n+c)/2;
                if(x1&1)b1[i] = 1;
            }
        cout<<2<<" "<<b1.to_ulong()<<endl;
        cin>>outcome;
        if(outcome == -1)break;
    }
}