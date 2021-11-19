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

struct point
{
    int x, y;

    bool operator<(point &A)
    {
        if (x == A.x)
            return y < A.y;
        return x < A.x;
    }

    bool operator==(point &A)
    {

        return (x == A.x and y == A.y);
    }
};

//orientation
bool cw(point a, point b, point c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

bool ccw(point a, point b, point c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

vector<point> convex_hull(vector<point> &P)
{
    //nlogn + n
    int n = P.size();

    //base case
    if (n <= 2)
        return P;

    vector<point> up, down;
    sort(P.begin(), P.end());
    point beg = P[0], end = P[n - 1];

    up.EB(beg);
    down.EB(beg);

    for (int i = 1; i < n; i++)
    {
        //upper portion
        if (!ccw(beg, P[i], end))
        {
            while (up.size() >= 2 and ccw(up[up.size() - 2], up[up.size() - 1], P[i]))
            {
                up.pop_back();
            }
            up.EB(P[i]);
        }

        if (!cw(beg, P[i], end))
        {
            while (down.size() >= 2 and cw(down[down.size() - 2], down[down.size() - 1], P[i]))
            {
                down.pop_back();
            }
            down.EB(P[i]);
        }
    }

    vector<point> ans;
    for (int i = 0; i < up.size(); i++)
        ans.EB(up[i]);
    for (int i = 0; i < down.size(); i++)
        ans.EB(down[i]);
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    return ans;
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
        int n;
        cin >> n;
        point tmp;
        vector<point> P;
        map<pair<int, int>, int> mp;

        for (int i = 0; i < n; i++)
        {
            cin >> tmp.x >> tmp.y;
            P.EB(tmp);
        }

        cin >> n;
        
        for (int i = 0; i < n; i++)
        {
            cin >> tmp.x >> tmp.y;
            mp[{tmp.x, tmp.y}]++;
            P.EB(tmp);
        }

        vector<point> ans = convex_hull(P);

        for (auto pot : ans)
            {
                // cout << pot.x << " " << pot.y << '\n';
                if (mp.count({pot.x, pot.y}))
                {
                    cout << "NO\n";
                    return 0;}
            }
            cout << "YES\n";
    }
}
