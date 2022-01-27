#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)

int n;
int A[100005][2];

bool can_meet(double t){

    double l = -1e9;
    double r = 1e9;
    double tmp;
    for(int i = 0;i<n;i++){
        tmp = A[i][0] - A[i][1]*t;
        l = max(l,tmp);
        tmp = A[i][0] + A[i][1]*t;
        r = min(r,tmp);
    }
    return l<=r;
}

double solve(){
    double l = 0.0;
    double r = 1.0;

    while(!can_meet(r))r*=2;

    for(int i = 0;i<100;i++){
        double m = (l+r)/2;

        if(can_meet(m))
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
    while (t--)
    {
        cin>>n;
        for(int i = 0;i<n;i++)
            cin>>A[i][0]>>A[i][1];
        
        cout<<setprecision(20)<<solve()<<'\n';
    }
}
