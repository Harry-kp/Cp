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
     
     
int A[1005][1005];
int B[1005][1005];

void consecutive_row_cells_operation(int x,int n,int m){
    int i,j,ii,jj,diff;
    for(i = 0;i<n;i++){
        for(j = 0;j<m-x+1;j++){
            if(A[i][j] != B[i][j]){
                // cout<<"row"<<'\n';
                diff = B[i][j] - A[i][j];
                for(jj = j;jj<j+x;jj++)
                    A[i][jj]+=diff;
            }
        }
    }
}

void consecutive_col_cells_operation(int x,int n,int m){
    int i,j,ii,jj,diff;
    for(j = 0;j<m;j++){
        for(i = 0;i<n-x+1;i++){
            if(A[i][j] != B[i][j]){
                // cout<<"col"<<'\n';

                diff = B[i][j] - A[i][j];
                for(ii = i;ii<i+x;ii++)
                    A[ii][j]+=diff;
            }
        }
    }
}

int32_t main(){
    int t,n,m,x,i,j;
    cin>>t;
    
    while(t--){
        cin>>n>>m>>x;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>A[i][j];
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>B[i][j];
            }
        }
        
        consecutive_row_cells_operation(x,n,m);
        // for(i = 0;i<n;i++){
        //     for(j = 0;j<m;j++){
        //         cout<<A[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }

        // for(i = 0;i<n;i++){
        //     for(j = 0;j<m;j++){
        //         cout<<B[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }
        consecutive_col_cells_operation(x,n,m);

        bool no = false;
        // for(i = 0;i<n;i++){
        //     for(j = 0;j<m;j++){
        //         cout<<A[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }

        // for(i = 0;i<n;i++){
        //     for(j = 0;j<m;j++){
        //         cout<<B[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }
        for(i = 0;i<n;i++)
            for(j = 0;j<m;j++){
                if(A[i][j] != B[i][j]){
                    no = true;
                }
            }
        
        if(no)cout<<"No\n";
        else cout<<"Yes\n";


    }
}