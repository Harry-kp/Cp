

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

int divi(int n)
{
    int ans = 0;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            
            if (n/i == i)
                ans+=i;
 
            else // Otherwise print both
               ans = ans + i + n/i;
        }
    }
    return ans;
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
        int x,a,b;
        cin>>x>>a>>b;
        if((b*x)%a!=0)
            {cout<<-1<<'\n';
            continue;
            }
        int ans = (b*x)/a;
        if(ans>1e9)
        {
            cout<<-1<<'\n';
            continue;
        }
        if(divi(ans) == x)
        cout<<ans<<'\n';
        else
            cout<<-1<<'\n';
    }
}

