#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)
#define PI(a, b) pair<a, b>
#define MP make_pair
#define EB emplace_back
#define MOD 1000000007
#define int long long
#define S second
#define F first
#define endl '\n'
#define FOR(var, len) for (var = 0; var < len; var++)
#define debug1 cout << "debug1" << '\n'
#define debug2 cout << "debug2" << '\n'
#define debug3 cout << "debug3" << '\n'
#define max_l 1000005

int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        int dp[n+1];
        fill(dp,dp+n+1,100000000000);
        dp[0] = 0;
        int tmp = n,dig;
        for(int i = 1;i<=n;i++){
            tmp = i;
            while(tmp>0){
                dig  = tmp%10;
                tmp/=10;

                if(i-dig>=0){
                    dp[i] = min(dp[i],dp[i-dig]);
                }
            }
            dp[i]++;
        }
        cout<<dp[n]<<'\n';
    }
}