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
        int n;
        cin>>n;
        int A[n][n];
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
                cin>>A[i][j];
        
        n--;
        bool flip  = false;
        int count1 = 0;
        while(n>0){
            if(flip){
                if(A[0][n] == n+1){
                flip = false;
                // debug2;
                count1++;
                }
            }
                
            else{
                if(A[0][n]!=n+1){
                    // debug1;
                    flip = true;
                    count1++;
                }
            }
               
            n--;
        }
        cout<<count1<<endl;
    }
}