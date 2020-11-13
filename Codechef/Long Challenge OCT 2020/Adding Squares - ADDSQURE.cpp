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
#define max_l            100000
#define SIZE             100001


int32_t main(){
    fastio ;
    int N,H,W,M;
    cin>>W>>H>>N>>M;


    bitset<SIZE> X;
    bitset<SIZE> Y;
    bitset<SIZE> Y_dup;
    bitset<SIZE> X_diff;
    bitset<SIZE> Y_diff;
    bitset<SIZE> Xynot;

    int i,j,tmp;

    for(i = 0;i<N;i++){
        cin>>tmp;
        X[tmp] = 1;
        
    }
    for(i = 0;i<M;i++){
        cin>>tmp;
        Y[tmp] = 1;
    }

    Y_dup|=Y;

    while(X.count()>0 or Y.count()>0){
        if(X[0] == 1){
            X_diff|=X;
        }
        if(Y[0] == 1){
            Y_diff|=Y;
        }
            X>>=1;
            Y>>=1;
    }

    int mx = -1;
    Xynot|= X_diff&~Y_diff;
    

    auto str1 = Y_dup.to_string();
    reverse(str1.begin(), str1.end());
    bitset<SIZE> Y_rev(str1);
    

    for(i = 0;i<=H;i++){
        if(Y_dup[i] == 0){
            int or1 = (int)(((Y_dup>>i)|(Y_rev>>(SIZE-1-i)))&(Xynot)).count();
            mx = max(mx,or1);
        }
    }

    int ans = (int)(X_diff & Y_diff).count();

    cout<<ans-1+ mx<<endl;
    

    
}