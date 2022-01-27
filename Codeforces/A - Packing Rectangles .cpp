#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define int long long int

bool good(int sq,int w,int h,int n){
    return ((sq/w) * (sq/h))>=n;
}


// minimum value of side of square to cover all rectangles

int solve(int n,int w,int h,int sq){
    int l = sq/2;
    int r = sq;

    while(r-l>1){
        int m = (r+l)/2;
        if(good(m,w,h,n))
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
        // find approx value of side of sqaure
        int w,h,n;
        cin>>w>>h>>n;

        int sq = 1;
        while(!good(sq,w,h,n))
            sq*=2;
        
        cout<<solve(n,w,h,sq)<<'\n';
    }
}
