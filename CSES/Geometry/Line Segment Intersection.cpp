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

void solve()
{
    P p1, p2, p3, p4;
    p1.read();
    p2.read();
    p3.read();
    p4.read();

    //if segments are parallel
    if ((p2 - p1) * (p4 - p3) == 0){

        //if segments are not collinear
        if(p1.triangle(p2,p3)!=0){
            cout << "NO\n";
            return;
        }


        //if segments are collinear
        for (int i = 0; i < 2;i++){
            //if there bounding boxes i.e rectangle intersect or not

            if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)){
                cout << "NO\n";
                return;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
        cout << "YES\n";
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        int sign1 = p1.triangle(p2,p3);
        int sign2 = p1.triangle(p2,p4);

        //segment 2 either totally left or totally right
        if ((sign1 > 0 and sign2 > 0) or (sign1 < 0 and sign2 < 0))
        {
            cout << "NO\n";
            return;
        }

        swap(p1, p3);
        swap(p2, p4);
    }
    cout << "YES\n";
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
        solve();
    }
}
