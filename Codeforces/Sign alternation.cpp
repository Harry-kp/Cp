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

    int size;
    vector<int> sums;

    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;

        sums.assign(2 * size, 0);
    }

    void build(vector<int> &A, int x, int lx, int rx)
    {

        if (rx - lx == 1)
        {
            if (lx < (int)A.size())
            {
                sums[x] = A[lx];
            }
            return;
        }

        int m = (lx + rx) / 2;
        build(A, 2 * x + 1, lx, m);
        build(A, 2 * x + 2, m, rx);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void build(vector<int> &A)
    {
        build(A, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx)
    {

        if (rx - lx == 1)
        {
            sums[x] = v;
            return;
        }

        int m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);

        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    int sum_query(int l, int r, int x, int lx, int rx)
    {

        if (lx >= r || rx <= l)
            return 0;

        if (lx >= l && rx <= r)
            return sums[x];

        int m = (lx + rx) / 2;

        return sum_query(l, r, 2 * x + 1, lx, m) + sum_query(l, r, 2 * x + 2, m, rx);
    }

    int sum_query(int l, int r)
    {
        return sum_query(l, r, 0, 0, size);
    }
};

int32_t main()
{

    int n, m, tmp;
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if(i%2!=0)tmp = -tmp;
        A[i] = tmp;
    }
    cin >> m;
    segtree st;
    st.init(n);
    st.build(A);

    int a, b, c;
    while (m--)
    {
        cin >> a >> b >> c;

        if (a == 0)
        {
            if ((b-1)%2 == 1)
                c = -c;
            st.set(b - 1, c);
        }
        else
        {
            tmp = st.sum_query(b - 1, c);
            if((b-1)%2 == 1)
                tmp = -tmp;
            cout<<tmp<<endl;
        }
    }
}