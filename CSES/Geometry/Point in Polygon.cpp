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

struct P
{
    int x, y;

    void read()
    {
        cin >> x >> y;
    }

    bool operator<(P &a)
    {
        if (x == a.x)
            return y < a.y;
        return x < a.x;
    }

    bool operator==(P &a)
    {

        return (x == a.x and y == a.y);
    }

    P operator-(const P &a) const
    {
        return P({x - a.x, y - a.y});
    }

    void operator-=(const P &a)
    {
        x -= a.x;
        y -= a.y;
    };

    int operator*(const P &a) const
    {
        return (x * a.y) - (a.x * y);
    }

    int triangle(const P &b, const P &c)
    {
        return (b - *this) * (c - *this);
    }
};

bool intersect(P a, P b, P c, P d)
{

    //Case 1 :- if slope of both vector are same
    if ((b - a) * (d - c) == 0)
    {
        // Case 1.1 if they are not colliear i.e maybe parallel ..slope of parallel lines are equal also
        if (a.triangle(b, c) != 0)
        {
            return false;
        }

        // Case 1.2 if they are collinear there are two possibility
        // |-------| ||-----||  or |-----||--|-----||

        for (int rep = 0; rep < 2; rep++)
        {
            if ((max(a.x, b.x) < min(c.x, d.x)) or (max(a.y, b.y) < min(c.y, d.y)))
            {
                return false;
            }
            swap(a, c);
            swap(b, d);
        }
        return true;
    }

    {
        for (int i = 0; i < 2; i++)
        {
            int sign1 = a.triangle(b, c);
            int sign2 = a.triangle(b, d);

            if ((sign1 < 0 and sign2 < 0) or (sign1 > 0 and sign2 > 0))
            {
                return false;
            }

            swap(a, c);
            swap(b, d);
        }
        return true;
    }
}

bool segment_contains(P a, P b, P c)
{
    if (a.triangle(b, c) != 0)
        return false;

    return (min(a.x, c.x) <= b.x and max(a.x, c.x) >= b.x and min(a.y, c.y) <= b.y and max(a.y, c.y) >= b.y);
}

int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<P> point(n);

        for (int i = 0; i < n; i++)
        {
            point[i].read();
        }

        for (int i = 0; i < m; i++)
        {
            P tmp;
            tmp.read();
            P out = P{tmp.x + 1, 3000000005};
            int cnt = 0;
            bool bound = false;
            for (int i = 0; i < n; i++)
            {
                if (intersect(tmp, out, point[i], point[(i + 1) % n]))
                    cnt++;

                if (segment_contains(point[i], tmp, point[(i + 1) % n]))
                {
                    bound = true;
                    break;
                }
            }

            if(bound)
                cout << "BOUNDARY\n";
            else if(cnt%2 == 0)
                cout << "OUTSIDE\n";
            else
                cout << "INSIDE\n";
        }
    }
}
