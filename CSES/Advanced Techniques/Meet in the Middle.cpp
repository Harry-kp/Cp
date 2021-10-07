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

vector<int> subset(int A[], int n)
{
    int j, k, sum1;
    vector<int> ans;
    for (int i = 0; i < (1 << n); i++)
    {
        sum1 = 0;
        j = i;
        k = 0;
        while (j)
        {
            if (j & 1)
                sum1 += A[k];
            k++;
            j >>= 1;
        }
        ans.EB(sum1);
    }
    return ans;
}


// Using hashing for frequency count is leading to TLE.Don't know why
// Hence I used lower_bound and upper_bound
int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, n1, n2, x, j, k;
        cin >> n >> x;
        n1 = n >> 1;
        n2 = n - n1;

        int A[n1], B[n2];
        vector<int> l1(1 << n1), l2(1 << n2);
        for (int i = 0; i < n; i++)
        {
            if (i < n1)
                cin >> A[i];
            else
                cin >> B[i - n1];
        }

        l1 = subset(A, n1);
        l2 = subset(B, n2);

        sort(l1.begin(), l1.end());
        sort(l2.begin(), l2.end());
        int cnt = 0;
        for (auto u : l1)
        {
            cnt += (upper_bound(l2.begin(), l2.end(), x - u) - lower_bound(l2.begin(), l2.end(), x - u));
        }
        cout << cnt << '\n';
    }
}
