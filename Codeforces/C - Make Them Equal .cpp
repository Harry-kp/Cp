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
        int n;
        char c;
        string s;
        cin>>n>>c>>s;
        bool flag = true, ret = false;
        // 0th case
        for(auto x:s)
            if(x!=c)flag = false;
        if(flag){
            cout<<0<<'\n';
            continue;
        }
       

        for(int x = 1;x<=n;x++){
            flag = true;
            for(int j = x;j<=n;j+=x)
                if(s[j-1] !=c){
                    flag = false;
                    break;
                }
            if(flag){
                cout<<1<<'\n'<<x<<'\n';
                ret = true;
                break;
            }
        }
        if(ret)continue;
        
        cout<<2<<'\n'<<n<<" "<<n-1<<'\n';
    }
}
