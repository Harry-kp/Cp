#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
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
int binExp(int a, int b, int m){int r = 1;while (b){if (b % 2 == 1)r = (r * a) % m;a = (a * a) % m;b = b / 2;}return r;}

int modinv(int x,int m){
    return binExp(x,m-2,m);
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


void solve(){
    int n;
    cin >> n;

    vector<P> point(n);

    for (int i = 0; i < n;i++){
        point[i].read();
    }

    int area = 0;

    for (int i = 0; i < n;i++){
        area += (point[0].triangle(point[i], point[(i + 1) % n]));
    }
    area = abs(area);
    cout << area << '\n';
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
        solve();
    }
}
