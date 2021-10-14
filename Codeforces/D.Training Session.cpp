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
        int n,u,v;
        cin>>n;
        int cnt[n][2],num[n],den[n];
        for (int i = 0; i < n; i++)
        {
            cnt[i][0] = cnt[i][1] = 0;
        }
        for(int i = 0;i<n;i++){
            cin>>u>>v;
            u--;v--;
            num[i] = u;
            den[i] = v;
            cnt[u][0]++;
            cnt[v][1]++;
        }

        int ans = (n*(n-1)*(n-2))/6;
        for(int i = 0;i<n;i++){
            ans -= (cnt[num[i]][0]-1)*1LL*(cnt[den[i]][1]-1);
        }
        cout<<ans<<'\n';

    }
}
