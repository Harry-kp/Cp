#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)

double c;
bool good(double x){
    return x*x*x*x + x>=c;
}

double solve(){
    double l = 0.0;
    double r=1.0;

    // approx value of l
    while(!good(r))
        r*=2;
    
    for(int i = 0;i<70;i++){
        double m = (r+l)/2;

        if(good(m))
            r=m;
        else
            l=m;
    }
    return r*r;
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
        cin>>c;
        cout<<setprecision(20)<<solve()<<'\n';
    }
}
