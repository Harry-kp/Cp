// Using binary lifting technique
#include <bits/stdc++.h>
#define int long long
using namespace std;


const int N = 2* 1e5 + 5;
const int ex = log2(N)+3;

int up[N][ex];


int32_t main() {
    int n,q;
    cin>>n>>q;
    memset(up,-1,sizeof(up));
    
    for(int i = 2;i<=n;i++){
        cin>>up[i][0];
    }
    
    // preprocess in nlogn
    
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<ex;j++){
            if(up[i][j-1]!=-1)
                up[i][j] = up[up[i][j-1]][j-1];
        }
    }
    
    // solve queries 
    int x,k;
    for(int i = 1;i<=q;i++){
        cin>>x>>k;
        
        for(int i = 0;i<ex;i++){
            if(x!=-1)
                if(k&(1<<i))
                    x = up[x][i];
            
        }
        cout<<x<<'\n';
    }
    
}
