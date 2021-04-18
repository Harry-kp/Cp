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
     
    
int32_t main(){
    int t,n,d,e;
    cin>>t;
    int ans[] = {0,20,36,51,60,76,88,99,104};
    while(t--){
        cin>>n;
        d = n%4;
        e = n/4;
        if(e == 0)e+=1;
        cout<<44*(e - 1) + ans[n - (e-1)*4]<<endl;
    }
}