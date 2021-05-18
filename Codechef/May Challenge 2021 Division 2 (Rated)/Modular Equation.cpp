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
#define max_l 1000005

vector<int> divisors[5*100002+1];

void createDivisors(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * i <= n; j++)
            divisors[i * j].EB(i);
    }

}

void solve(int n, int m, int &pre)
{
    int right;
    for (int i = 3; i <= n; i++)
    {
        right = m % i;
        if (m == right)
        {
            pre = pre + i - 1;
        }
        else
        {
            int tmp = abs(m - right);
            pre = pre + (upper_bound(divisors[tmp].begin(), divisors[tmp].end(), i - 1) - divisors[tmp].begin());
        }
    }
}

int32_t main()
{
    fastio;
    createDivisors(5*100002);
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int pre = 1;
        if(n>m && m>1){
            solve(m,m,pre);
            for(int i = m;i<n;i++)pre+=i;
            cout<<pre<<'\n';
        }else{
        solve(n, m, pre);
        cout << pre << '\n';
        }
    }
}
