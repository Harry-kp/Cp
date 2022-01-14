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

int dp[15][100][2];

vector<int> dtoa(int n){
    vector<int> ans;
    while(n){
        ans.EB(n%10);
        n/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
}

int solve(int i,int n,int cur_ans,bool limit,vector<int>& digit){

    if(dp[i][cur_ans][limit]!=-1)return dp[i][cur_ans][limit];
    if(i == n)return cur_ans;

    int ans = 0;
    int l = 9;
    if(limit)l = digit[i];

    for(int j = 0;j<=l;j++){
        if(!limit or j<l)
            ans += solve(i+1,n,cur_ans+j,false,digit);
        else
            ans += solve(i+1,n,cur_ans+j,true,digit);
    }

    return dp[i][cur_ans][limit] = ans;
}

int getSum(int n){
    if(n<=0)return 0;

    vector<int> digit = dtoa(n);
    return solve(0,digit.size(),0,true,digit);

}
int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;

    int a,b;
    while (1)
    {
        cin>>a>>b;
        
        if(a == -1)break;
        memset(dp,-1,sizeof dp);
        int r = getSum(b);
        memset(dp,-1,sizeof dp);
        int l = getSum(a-1);
        cout<<r-l<<'\n';
    }
}
