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
#define int long long int
#define S second
#define F first
#define FOR(var, len) for (var = 0; var < len; var++)
#define debug1 cout << "debug1" << '\n'
#define debug2 cout << "debug2" << '\n'
#define debug3 cout << "debug3" << '\n'

// int dr[] = {0,-1,0,1,-1,-1,1,1};
// int dc[] = {-1,0,1,0,-1,1,1,-1};

// Maths Utils
int binExp(int a, int b, int m)
{
    int r = 1;
    while (b)
    {
        if (b % 2 == 1)
            r = (r * a) % m;
        a = (a * a) % m;
        b = b / 2;
    }
    return r;
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

        int n, k;
        cin >> n >> k;
        int A[n], time[n];

        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
            if (A[i] > 0)
                time[i] = 0;
            else
                time[i] = 100000000;
        }

        //2*n to propogte the circular effect
        for (int i = 0; i < 2 * n; i++)
        {
            time[(i + 1) % n] = min(time[(i + 1) % n], time[i % n] + 1);
        }

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            time[(i - 1 + n) % n] = min(time[(i - 1 + n) % n], time[i % n] + 1);
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans = ans + A[i] + 2 * max(0ll, k - time[i]);
        }
        cout << ans << '\n';
    }
}
