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
    vector<int> tree;

    void init(int n)
    {
        size = 1;
        while (size < n)
        {
            size = size * 2;
        }
        tree.assign(2 * size, 0);
    }

    void build(vector<int> &A)
    {
        build(A, 0, 0, size);
    }

    void build(vector<int> &A, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)A.size())
            {
                tree[x] = 0;
            }
            return;
        }

        int m = (rx + lx) / 2;
        build(A, 2 * x + 1, lx, m);
        build(A, 2 * x + 2, m, rx);

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void update(int ind, int val)
    {
        update(ind, val, 0, 0, size);
    }

    void update(int ind, int val, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx == ind)
                tree[x] += val;
            return;
        }

        int m = (rx + lx) / 2;
        if (ind < m)
        {
            update(ind, val, 2 * x + 1, lx, m);
        }
        else
        {
            update(ind, val, 2 * x + 2, m, rx);
        }

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    int query(int l, int r)
    {
        return query(l, r, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx)
    {
        if (l >= rx or r <= lx)
            return 0;
        if (lx >= l and r >= rx)
            return tree[x];

        int m = (lx + rx) / 2;
        return query(l, r, 2 * x + 1, lx, m) + query(l, r, 2 * x + 2, m, rx);
    }
};

int32_t main()
{
    int n, m, a;
    cin >> n >> m;
    // vector<int> input(n);

    segtree st;
    st.init(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        if (a == 1)
        {
            int b, c, d;
            cin >> b >> c >> d;
            st.update(b, d);
            if (c != n)
                st.update(c, -d);
        }
        else
        {
            int i;
            cin >> i;
            cout << st.query(0, i + 1) << endl;
        }
    }
}