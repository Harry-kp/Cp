#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define int long long int

// check if cut is valid
bool can_be_cutted(double temp,vector<int>& rope,int k){

    int cnt = 0;
    for(int i = 0;i<rope.size();i++){
        cnt +=floor(rope[i])/temp;
    }
    return cnt>=k;
}

// maximum length of piece of rope to cut
double solve(vector<int>& rope,int k){
    double l = 0 ;
    double r = 100000000;

    for(int i = 0;i<100;i++){
        double m = (r+l)/2;
        if(can_be_cutted(m,rope,k))
            l=m;
        else
            r=m;
    }
    return l;
}

int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;

        vector<int> rope(n);
        for(int i = 0;i<n;i++)cin>>rope[i];
        // set precision is the key for AC in this question
        cout<<setprecision(20)<<solve(rope,k)<<'\n';
    }
}
