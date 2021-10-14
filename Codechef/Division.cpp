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

#include <bits/stdc++.h>
using namespace std;

map<int,int> dp;
vector<int> divi(int n)
{
    vector<int> ans;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal, print only one
            if (n / i == i and i!=1)
                ans.EB(i);

            else // Otherwise print both
                {
                    if(i!=1)
                        ans.EB(i);
                    if(n/i!=1)
                        ans.EB(n/i);
                }
        }
    }
    return ans;
}

int solve(vector<int>& pm,int n,int o,int e){
    if(dp.count(n))return dp[n];
    if(n == 1)return 0;
    int max1  = INT_MIN;

    for(auto x:pm){
        if(n%x == 0)
        {if(x%2 == 0){
            max1 = max(max1,e + solve(pm,n/x,o,e));
        }
        else{
            max1 = max(max1,o+solve(pm,n/x,o,e));
        }}
    }
    dp[n] = max1;
    return max1;
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
        int n,o,e;
        cin>>n>>e>>o;
        vector<int> pm = divi(n);
        cout<<solve(pm,n,o,e)<<'\n';
        dp.clear();
    }
    
}
