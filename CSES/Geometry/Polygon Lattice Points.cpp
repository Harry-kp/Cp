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


int gcd(int a,int b){
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    return __gcd(a, b);
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
        vector<P> p(n);
        for (int i = 0; i < n;i++){
            p[i].read();
        }

        int area = 0;
        int boundary = 0;
        for (int i = 0; i < n; i++)
        {
            int j = (i + 1) % n;
            area += (p[i] * p[j]);
            P tmp = p[i] - p[j];
            boundary += gcd(abs(tmp.x), abs(tmp.y));
        }
        //pick's theorem
        //A = i + b/2 - 1
        //2*A = 2*i + b-2
        // i = (2*A+2-b)/2
        int inside = (abs(area) + 2 - boundary)/2;

        cout << inside << " " << boundary << '\n';
    }
}
