#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define EB emplace_back
#define MOD 998244353
#define int long long int
#define S second
#define F first
#define debug1 cout << "debug1" << '\n'
#define debug2 cout << "debug2" << '\n'
#define debug3 cout << "debug3" << '\n'


// int dr[] = {0,-1,0,1,-1,-1,1,1};
// int dc[] = {-1,0,1,0,-1,1,1,-1};


// Maths Utils
int binexp(int a, int b, int m){int r = 1;while (b){if (b % 2 == 1)r = (r * a) % m;a = (a * a) % m;b = b / 2;}return r;}

int modinv(int x,int m){
    return binexp(x,m-2,m);
}


int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;cin>>n;
        int A[n];
        for(int i = 0;i<n;i++){
            cin>>A[i];
        }
        sort(A,A+n);
        vector<int> dp(n);
        // dp  - ith state tells the length of expected array if we choose ith index as starting index
        
        // base case ,for last index (n-1) dp[i] = 1.because there is only one possibility i.e the number itself
        dp[n-1] = 1;
        int sum1 = 1;
        for(int i = n-2;i>=0;i--){
            if(A[i] == A[i+1])
                dp[i] = dp[i+1];
            else
                dp[i] = (1 + sum1*modinv(n-i-1,MOD))%MOD;
            sum1 = (sum1 + dp[i]) % MOD;
        }
        int ans = (sum1 * modinv(n,MOD))%MOD;
        cout<<ans<<'\n';
    }
}
