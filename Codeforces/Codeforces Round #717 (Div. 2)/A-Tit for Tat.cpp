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

int32_t main()
{
    fastio;
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (k == 0)
                break;
            if (A[i] >= k)
            {
                A[i] -= k;

                A[n - 1] += k;
                k = 0;
            }
            else
            {
                A[n - 1] += A[i];
                k -= A[i];
                A[i] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
}