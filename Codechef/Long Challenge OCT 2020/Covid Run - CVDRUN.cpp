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


bool check(vector<int>& arr){
    for(int i = 0;i<arr.size()-1;i++){
        if(arr[i]&arr[i+1] == 0)return false;
    }
    return true;
}

int32_t main(){
    fastio ;
    int t;
    cin>>t;
    while(t--){
        int n,k,x,y,i;
        cin>>n>>k>>x>>y;
        bool ans = false;
        for(i = 0;i<=10000;i++)
        {   
            if(x == y){ans = true;}
            x = (x+k)%n;
        }
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}