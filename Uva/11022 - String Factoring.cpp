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

int modinv(int x,int m){
    return binExp(x,m-2,m);
}

int dp[90][90];

// this function uses dp with pi function in kmp
int solve(string s,int l,int r){
    if(dp[l][r]!=-1)return dp[l][r];
    if(l == r)return 1;
    dp[l][r] = INT_MAX;

    for(int i = l;i<r;i++){
        dp[l][r] = min(dp[l][r],solve(s,l,i) + solve(s,i+1,r));
    }

    int pi[r-l+1];
    pi[0] = 0;

    // generate pi function of substring l->r
    for(int i = l+1;i<=r;i++){
        int j = pi[i-l-1];
        while(j>0 and s[i]!=s[l+j])
            j = pi[j-1];
        if(s[i]==s[l+j])
            j++;
        pi[i-l] = j;
    }

    int n = r-l+1;
    int m = n - pi[n-1];
    if(n%m == 0)
        dp[l][r] = min(dp[l][r],solve(s,l,l+m-1));
    return dp[l][r];
}


int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    while (1)
    {
        string s;
        cin>>s;
        if(s == "*")break;
        memset(dp,-1,sizeof dp);
        cout<<solve(s,0,s.size()-1)<<'\n';
        
    }
}
