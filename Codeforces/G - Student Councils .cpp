#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define int long long int

int k;
int n;
int A[55];


bool good(int cou){
    // total seats in number of council (cou) with each having k candidates
    int seats = cou*k;
    // Let,
    // piegeons - A[i]
    // pigeonholes - cou
    // so according to pigeonhole principle if A[i]>cou then there will be duplicates hence we will take only minimum of these
    for(int i = 0;i<n;i++){
        seats-=min(cou,A[i]);
    }
    // if seats can be filled
    return seats<=0;
}

int solve(){
    int l = 0;
    int r = 1;
    while(good(r))r*=2;

    while(l+1<r){
        int m = (l+r)/2;
        // cout<<l<<" "<<r<<" "<<m<<'\n';
        if(good(m))
            l=m;
        else
            r=m;
    }
    // 
    return l;
}

int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {   
        cin>>k>>n;
        for(int i = 0;i<n;i++)cin>>A[i];
        cout<<solve()<<'\n';
    }
}
