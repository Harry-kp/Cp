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

struct segtree
{

    int size, mod;
    vector<vector<int>> sums;

    void init(int n, int r)
    {
        size = 1;
        mod = r;
        while (size < n)
            size *= 2;

        sums.assign(2 * size, {0, 0, 0, 0});
    }

    vector<int> product(vector<int> &l, vector<int> &r)
    {
        int a, b, c, d;
        a = ((l[0] * r[0]) % mod + (l[1] * r[2]) % mod) % mod;
        b = ((l[0] * r[1]) % mod + (l[1] * r[3]) % mod) % mod;
        c = ((l[2] * r[0]) % mod + (l[3] * r[2]) % mod) % mod;
        d = ((l[2] * r[1]) % mod + (l[3] * r[3]) % mod) % mod;
        return {a, b, c, d};
    }

    void build(vector<vector<int>> &A, int x, int lx, int rx)
    {

        if (rx - lx == 1)
        {
            if (lx < (int)A.size())
            {
                sums[x] = {A[lx][0], A[lx][1], A[lx][2], A[lx][3]};
            }
            return;
        }

        int m = (lx + rx) / 2;
        build(A, 2 * x + 1, lx, m);
        build(A, 2 * x + 2, m, rx);
        sums[x] = product(sums[2 * x + 1], sums[2 * x + 2]);
    }

    void build(vector<vector<int>> &A)
    {
        build(A, 0, 0, size);
    }

    // void set(int i, int v, int x, int lx, int rx)
    // {

    //     if (rx - lx == 1)
    //     {
    //         sums[x] = v;
    //         return;
    //     }

    //     int m = (lx + rx) / 2;
    //     if (i < m)
    //         set(i, v, 2 * x + 1, lx, m);
    //     else
    //         set(i, v, 2 * x + 2, m, rx);

    //     sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    // }

    // void set(int i, int v)
    // {
    //     set(i, v, 0, 0, size);
    // }

    vector<int> prod_query(int l, int r, int x, int lx, int rx)
    {

        if (lx >= r || rx <= l)
            return {0};

        if (lx >= l && rx <= r)
            return sums[x];

        int m = (lx + rx) / 2;
        vector<int> t1, t2;
        t1 = prod_query(l, r, 2 * x + 1, lx, m);
        t2 = prod_query(l, r, 2 * x + 2, m, rx);
        if (t1.size() == 1)
            return t2;
        if (t2.size() == 1)
            return t1;
        return product(t1, t2);
    }

    vector<int> prod_query(int l, int r)
    {
        return prod_query(l, r, 0, 0, size);
    }
};

int32_t main()
{
    fastio;
    int r, n, m, a, b;
    cin >> r >> n >> m;
    vector<vector<int>> input(n, vector<int>(4));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> input[i][j];
            input[i][j] %= r;
        }
    }

    segtree st;
    st.init(n, r);
    st.build(input);

    while (m--)
    {
        cin >> a >> b;
        vector<int> ans;
        ans = st.prod_query(a - 1, b);
        cout << ans[0] << " " << ans[1] << endl;
        cout << ans[2] << " " << ans[3] << endl;
        cout << endl;
    }
}