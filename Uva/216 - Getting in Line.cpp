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

vector<pair<int,int>> point(10);

int cost(pair<int,int> a,pair<int,int> b){
    return sqrt((a.F - b.F)*(a.F - b.F) + (a.S - b.S)*(a.S - b.S));
}

int tsp(int pos,int mask,int n){
    if(pos == (1<<n)-1)return cost(point[pos],point[0]);

    int min1 = INT_MAX;
    for(int v = 0;v<n;v++){
        if(v!=pos and (mask>>v)&1 == 0)
            min1 = min(min1,cost(point[pos],point[v]) + tsp(v,mask|(1<<v),n));
    }
    return min1;

}

int32_t main(){
    fastio ;
    int n,i,a,b;
    while(cin>>n){
        for(i = 0;i<n;i++){
            cin>>a>>b;
            point[i] = make_pair(a,b);
        }

        
        
        cout<<tsp(0,1,n)<<'\n';
        
    }

    

    
}