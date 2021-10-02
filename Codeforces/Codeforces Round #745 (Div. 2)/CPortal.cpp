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

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
   
    for(int i = 0;i<n;i++){
        char s[405];
        cin>>s;
        for(int j = 0;j<m;j++)
            grid[i][j] = (s[j] == '1');
    }

    
    // prefix sum
    for(int i = 0;i<n;i++)
    for(int j = 0;j<m;j++){
        if(i-1>=0)grid[i][j]+=grid[i-1][j];
        if(j-1>=0)grid[i][j]+=grid[i][j-1];
        if(i-1>=0 and j-1>=0)grid[i][j]-=grid[i-1][j-1];
    }

    auto get = [&](int r1, int c1, int r2, int c2)
    {
        int sum1 = grid[r2][c2];
        if(r1-1>=0)
            sum1 -= grid[r1 - 1][c2];
        if(c1-1>=0)
            sum1 -= grid[r2][c1 - 1];
        if(r1-1>=0 and c1-1>=0)
            sum1 += grid[r1 - 1][c1 - 1];
        return sum1;
    };

    auto inv = [&](int r1, int c1, int r2, int c2){
        return (r2-r1+1)*(c2-c1+1)-get(r1,c1,r2,c2);
    };

    int ans = n*m;
    for(int r1 = 0;r1<n;r1++)for(int c1 = 0;c1<m;c1++)
    for(int r2 = r1+4;r2<n;r2++)for(int c2 = c1+3;c2<m;c2++){
        
        int in_sum = get(r1+1,c1+1,r2-1,c2-1);
        if(in_sum>=ans)
            break;
        
        in_sum += inv(r1+1,c1,r2-1,c1);
        in_sum += inv(r1,c1+1,r1,c2-1);
        if(in_sum>=ans)break;

        ans = min(ans, in_sum + inv(r1 + 1, c2, r2 - 1, c2) + inv(r2, c1 + 1, r2, c2 - 1));
    }
    cout<<ans<<'\n';
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
        solve();
    }
}
