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
    // 0-based
    void update(int ind, int val)
    {
        update(ind, val, 0, 0, size);
    }

    void update(int ind, int val, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = val;
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

    //[l,r)
    int query(int l, int r)
    {
        return query(l, r, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx)
    {
        if (r <= lx or l >= rx)
            return 0;
        if (lx >= l and r >= rx)
            return tree[x];

        int m = (lx + rx) / 2;
        return query(l, r, 2 * x + 1, lx, m) + query(l, r, 2 * x + 2, m, rx);
    }
};

int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        struct segtree X, Y;
        X.init(n);
        Y.init(n);
        vector<int> cr(n), cc(n);
        int ty;
        for (int i = 0; i < q; i++)
        {
            cin >> ty;

            if (ty == 1)
            {
                int x, y;
                cin >> x >> y;
                x--;
                y--;

                if (++cr[x] == 1)
                    X.update(x, 1);
                if (++cc[y] == 1)
                    Y.update(y, 1);
            }
            if (ty == 2)
            {
                int x, y;
                cin >> x >> y;
                x--;
                y--;
                if (--cr[x] == 0)
                    X.update(x, 0);
                if (--cc[y] == 0)
                    Y.update(y, 0);
            }

            if (ty == 3)
            {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                x1--;
                y1--;
                if (x1 > x2)
                    swap(x1, x2);
                if (y1 > y2)
                    swap(y1, y2);
                if ((X.query(x1, x2) == x2 - x1) or (Y.query(y1, y2) == y2 - y1))
                    cout
                        << "Yes\n";
                else
                    cout << "No\n";
            }
        }
    }
}
