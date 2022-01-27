#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define int long long int 

const int MOD = 1e9+7;

void solve(){
    int n,k,tmp;
    cin>>n>>k;
    vector<int> freq(8010,0);

    for(int i = 0;i<n;i++){
        cin>>tmp;
        freq[tmp]++;
    }

    vector<int> prime;
    for(int i = 0;i<8010;i++){
        if(freq[i])
            prime.push_back(i);
    }

    n = prime.size();
    k  = min(n,k);


    int dp[n+1][k+1];
    memset(dp,0,sizeof dp);

    for(int i = 0;i<=n;i++){
        dp[i][0] = 1;
    }

    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=k;j++){
            dp[i][j] = (freq[prime[i-1]] * dp[i-1][j-1] + dp[i-1][j])%MOD;
        }
    
    int ans = 0;
    for(int i = 0;i<=k;i++)
        {
            ans+=dp[n][i];
            ans%=MOD;
        }
    cout<<ans<<'\n';
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
        solve();
    }
}
