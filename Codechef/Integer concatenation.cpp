#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define EB emplace_back
#define MOD 1000000007
#define int long long int
#define S second
#define F first
#define debug1 cout << "debug1" << '\n'
#define debug2 cout << "debug2" << '\n'
#define debug3 cout << "debug3" << '\n'


// int dr[] = {0,-1,0,1,-1,-1,1,1};
// int dc[] = {-1,0,1,0,-1,1,1,-1};


// Maths Utils
int binExp(int a, int b, int m){int r = 1;while (b){if (b % 2 == 1)r = (r * a) % m;a = (a * a) % m;b = b / 2;}return r;}




int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n,l,r;
        cin>>n>>l>>r;

        int A[n];
        for(int i = 0;i<n;i++)cin>>A[i];
        sort(A,A+n);

        int p ,tmp,L,R,ans = 0;
        for(int i = 0;i<n;i++){
            p = 1;
            tmp = A[i];
            while(tmp>0){
                p*=10;
                tmp/=10;
            }

            L = ceil((l*1.0 - A[i])/p*1.0);
            R = (r-A[i])/p;

            ans += (upper_bound(A,A+n,R)- lower_bound(A,A+n,L));
        }
        cout<<ans<<'\n';
    }
}
