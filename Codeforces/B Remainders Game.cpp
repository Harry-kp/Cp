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


int gcd(int a ,int b){return __gcd(a,b);}
int lcm(int a,int b){
    return ((a*b)/gcd(a,b));
}


// chinese reminder theorem says that:-
// x%c1 == a1  is known
// x%c2 == a2  is known

// then x%(lcm(c1,c2 .. cn)) is known
// here k is given in place of (lcm(c1,c2 .. cn)).So for a feasable solution,
// gcd((lcm(c1,c2 .. cn)),k) == k
// gcd(k,lcm(ans,tmp)) this formula checks for temporary lcm accumulated to avoid overflow
int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n,k,tmp;cin>>n>>k;
        int ans = 1;
        for(int i = 0;i<n;i++){
            cin>>tmp;
            ans = gcd(k,lcm(ans,tmp));
        }

        cout<<(ans == k?"Yes":"No")<<'\n';
    }
}
