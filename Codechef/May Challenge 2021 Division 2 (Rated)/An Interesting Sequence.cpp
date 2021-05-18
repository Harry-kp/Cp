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
#define max_l 4 * 1000005
#define ii pair<int, int>

int euler_phi[max_l];
int ans[max_l];

void Totient()
{
    euler_phi[0] = 0;
    euler_phi[1] = 1;
    for (int i = 2; i <max_l; i++)
        euler_phi[i] = i;

    for (int i = 2; i <max_l; i++)
    {
        if (euler_phi[i] == i)
        {
            for (int j = i; j < max_l; j += i)
                euler_phi[j] -= euler_phi[j] / i;
        }
    }
}

void solve()
{
    Totient();

    for (int i = 1; i < max_l; ++i)
    {   
        for (int j = 1; i * j < max_l; ++j)
        if( ((i*j) - 1)%4 == 0)
            ans[i * j] += i * (euler_phi[j]/2);
    }

}
int32_t main()
{
    fastio;
    solve();
    
    int t,k;
    cin>>t;
    while(t--){
        cin>>k;

        cout<<ans[4*k+1] + 4*k<<'\n';
    }
}