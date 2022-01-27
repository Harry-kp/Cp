#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
// #define int long long int

// minimum index whose value is greater than equal to key
int binary_search(vector<int> A,int k){
    int l = -1,r=A.size();
    while(r-l>1){
        int m = (r+l)/2;

        if(A[m]>=k)
            r=m;
        else
            l=m;
    }
    return r;
}

int32_t main()
{
    
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n,k,key;
        cin>>n>>k;
        vector<int> A(n);

        for(int i = 0;i<n;i++)
            cin>>A[i];
        for(int i = 0;i<k;i++){
            cin>>key;
            cout<<binary_search(A,key)+1<<'\n';

        }
    }
}
