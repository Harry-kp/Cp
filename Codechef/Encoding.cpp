#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define int long long int

const int MOD = 1e9+7;

int pow_10[100005];
int dp[100005][2][11];
int cntdp[100005][2];
string digit;

int cnt(int n,int tight){
    if(n == 0)
        return 1;
    if(!tight)
        return pow_10[n];
    
    if(cntdp[n][tight]!=-1)return cntdp[n][tight];

    int ub = tight?digit[digit.size()-n]-'0':9;
    int ans = 0;

    for(int j=0;j<=ub;j++)
        ans = (ans + cnt(n-1,tight&(j==ub)))%MOD;
    return cntdp[n][tight]=ans;
}


int solve(int n,int tight,int prev){
    if(n == 0)
        return 0;
    if(dp[n][tight][prev]!=-1)return dp[n][tight][prev];
    int ans = 0;
    int ub = tight?digit[digit.size()-n]-'0':9;
    
    for(int j = 0;j<=ub;j++){
        // int new_curr = cur;
        if(prev!=j)
        {
            int tmp = (j*pow_10[n-1])%MOD;
            tmp = (tmp * cnt(n-1,tight&(j==ub)))%MOD;
            ans  = (ans + tmp)%MOD;
        }
            
        ans += solve(n-1,tight&(j==ub),j);
        ans%=MOD;
    }
    return dp[n][tight][prev]=ans;
}


int brute(){
    int ans = 0;
    int prev = 10;

    for(int i = 0;i<digit.size();i++){
        int dig = digit[i]-'0';

        if(prev!=dig)
            ans = (ans + (pow_10[digit.size()-i-1]*dig)%MOD)%MOD;
        prev = dig;
    }
    return ans;
}

int32_t main()
{
    
    fastio;
    int t = 1;
    cin >> t;
    pow_10[0] = 1;
    for(int i = 1;i<=100001;i++)
        pow_10[i] = (pow_10[i-1] * 10)%MOD;
    
    while (t--)
    {   
        int n;
        memset(cntdp,-1,sizeof cntdp);
        memset(dp,-1,sizeof dp);
        cin>>n;
        cin>>digit;
        int l = solve(n,1,10);

        int excl = brute();

        memset(cntdp,-1,sizeof cntdp);
        memset(dp,-1,sizeof dp);
        cin>>n;
        cin>>digit;

        int r = solve(n,1,10);
        cout<<(r-l+excl+MOD)%MOD<<'\n';

    }
}
