#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
// # define int long long int 

int n,k;
int A[100000+5];

bool good(int m){
    int cnt = 0;
    int i = m;
    while(i>=0){
        int curr = (A[i] + cnt)%10;
        if(curr!=0)
            cnt += (10-curr);
        i--;
    }

    return cnt<=k;
}

int solve(){
    int l = -1;
    int r = n;

    while(l+1<r){
        int m = (l+r)/2;
        if(good(m))
            l=m;
        else
            r=m;
    }
    return l+1;
}
int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        cin>>n>>k;
        string s;
        cin>>s;
        for(int i = 0;i<n;i++)
            A[i] = s[i]-'0';

        cout<<solve()<<'\n';
    }
}