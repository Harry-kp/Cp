#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define int long long int
int n,x,y;

bool good(int sec){
    sec-=min(x,y);
    if(sec<0)return false;
    return ((sec/x) + (sec/y))>=n-1;
}

int solve(){
    int l = 0;
    int r = 2*(1e12)+5;

    while(r-l>1){
        int m = (r+l)/2;

        if(good(m))
            r=m;
        else
            l=m;
    }
    return r;
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
        cin>>n>>x>>y;
        cout<<solve()<<'\n';
    }
}
