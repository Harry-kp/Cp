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
    fastio ;
    int t;
    cin>>t;
    while(t--){
        int n,x,p,k,i;
        cin>>n>>x>>p>>k;
        int arr[n];
        // bool yes = false;
        for(i = 0;i<n;i++){
            cin>>arr[i];
            // if(arr[i] == x)yes = true;
        }
        sort(arr,arr+n);
        if(arr[p-1] == x)
            cout<<0<<endl;
        else if(k<=p and x>=arr[p-1]){
            int i = 0;
            while(p+i-1<n and x>arr[p+i-1]){
                i++;
            }
            // debug1;
            // if(arr[i+p-1]<x)i++;
            cout<<i<<endl;

        }
        else if(k>=p and x<=arr[p-1]){
            int i = 0;
            while(p-1-i>=0 and x<arr[p-i-1]){
                i++;
            }
            // debug2;
            // if(arr[p-i-1]>x)i++;    
            cout<<i<<endl;

        }
        else{
            cout<<-1<<endl;
        }

    }
}