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

int query(int t, int i, int j, int x)
{
    int ans;
    cout << "? " << t << " " << i << " " << j << " " << x << '\n';
    cout.flush();
    cin >> ans;
    return ans;
}

int maxFind(int n)
{
    int ans;
    for (int i = 1; i < n; i += 2)
    {
        ans = query(1, i, i + 1, n - 1);
        if (ans == n)
            return i + 1;
        else if (ans == n - 1)
        {
            ans = query(1, i + 1, i, n - 1);
            if (ans == n)
                return i;
        }
        else if (ans == -1)
            exit(1);
    }
    return n;
}

int32_t main()
{
    fastio;
    int arr[100000];
    int t;
    cin >> t;
    while (t--)
    {
        int n, mx, ans;
        cin >> n;
        mx = maxFind(n);
        arr[mx] = n;

        for (int i = 1; i <= n; i++)
        {
            if (i != mx)
            {
                ans = query(2, i, mx, 1);
                if (ans == -1)
                    exit(1);
                arr[i] = ans;
            }
        }
        cout << "! ";
        for (int i = 1; i <= n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';
        cout.flush();
    }
}