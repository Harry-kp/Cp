#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define int long long int

const int MOD = 1e9+7;

vector<vector<int>> matMul(vector<vector<int>> A,vector<vector<int>> B){
    vector<vector<int>> C(2,vector<int>(2));
    for(int i = 0;i<2;i++)
    for(int j = 0;j<2;j++)
    for(int k = 0;k<2;k++){
        C[i][j] += A[i][k]*B[k][j];
        C[i][j]%=MOD;
    }
    return C;
}

void binExp(vector<vector<int>> A,int n){
    vector<vector<int>> res = {{1,0},{0,1}};
    while(n){
        if(n%2 == 1)
            res = matMul(res,A);
        A = matMul(A,A);
        n/=2;
    }

    cout<<res[1][0]<<'\n';
}
int32_t main()
{

    fastio;
    int t = 1;
    while (t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> M = {{0,1},{1,1}};
        binExp(M,n);
    }
}
