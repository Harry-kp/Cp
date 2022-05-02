#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
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

int modinv(int x, int m)
{
    return binExp(x, m - 2, m);
}

// 0 -> 012
// 1 ->021/102
// 2 ->120/201
// 3->210

bool solve(int i, string s, const int &n, const vector<int> &inv)
{
    if (i == n)
        return true;

    char one = s[1];
    char two = s[2];

    // if current inv count is 0
    if (inv[i] == 0)
    {
        // if this is true,there is already one inversion in this substring
        if (one > two)
            return false;
        return solve(i + 1, "012", n, inv);
    }
    else if (inv[i] == 1)
    {
        if (one > two)
            return solve(i + 1, "102", n, inv);
        return solve(i + 1, "021", n, inv);
    }
    else if (inv[i] == 2)
    {
        if (one > two)
            return solve(i + 1, "201", n, inv);
        return solve(i + 1, "120", n, inv);
    }
    else
    {
        // there is already one inv less,hence cannot complete 3 inversion
        if (one < two)
        {
            return false;
        }
        return solve(i + 1, "210", n, inv);
    }
    return true;
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
        int n;
        cin >> n;
        vector<int> A(n);

        for (int i = 0; i < n; i++)
            cin >> A[i];

        bool ok;
        if (A[0] == 0)
            ok = solve(1, "012", n, A);
        else if(A[0] == 1)
            ok = solve(1, "021", n, A) | solve(1, "102", n, A);
        else if(A[0] == 2)
            ok = solve(1, "120", n, A) | solve(1, "201", n, A);
        else
            ok = solve(1, "210", n, A);

        cout << (ok ? "YES" : "NO") << '\n';
    }
}
