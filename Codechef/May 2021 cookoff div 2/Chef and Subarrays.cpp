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
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k, i, j;
        cin >> n >> k;
        int A[n];
        for (i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        int ans = 0;
        for (i = 0; i < k; i++)
        {
            map<int, int> m1;
            int cnt = 0;
            for (j = i; j < n; j += k)
            {
                m1[A[j]]++;
                cnt++;
            }
            int mx = 0;
            for (auto x : m1)
            {
                mx = max(mx, x.S);
            }
            ans += (cnt - mx);
        }
        cout << ans << '\n';
    }
}
