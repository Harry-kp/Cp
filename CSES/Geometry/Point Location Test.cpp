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

struct Point{
    int x, y;

    void read(){
        cin >> x >> y;
    }

    Point operator - (const Point &B) const{
        return Point({x - B.x, y - B.y});
    }

    void operator -= (const Point &B)
    {
        x -= B.x;
        y -= B.y;
    };

    int operator * (const Point &B) const {
        return (x * B.y) - (B.x * y);
    }

};

void solve()
{
    Point p1, p2, p3;
    p1.read();
    p2.read();
    p3.read();

    p2 -= p1;
    p3 -= p1;

    int cross = p2 * p3;

    if (cross < 0)
    {
        cout << "RIGHT\n";
    }
    else if (cross > 0)
        cout << "LEFT\n";
    else
        cout << "TOUCH\n";
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
