#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define int long long int

int n,k;
int A[100005];

bool possible(int s){
    int c = 0;
    int curr = 0;
    for(int i = 0;i<n;i++){
        if(A[i]>s)return false;
        curr+=A[i];
        if(curr>s){
            curr = A[i];
            c++;
        }
    }
    c++;
    return c<=k;
    
}

int solve(){
    int l = 0;
    int r = 1000000000000000;

    
    while(l+1<r){
        int m = (l+r)/2;
        if(possible(m))
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
        cin>>n>>k;
        for(int i = 0;i<n;i++)cin>>A[i];
        cout<<solve()<<'\n';
    }
}
