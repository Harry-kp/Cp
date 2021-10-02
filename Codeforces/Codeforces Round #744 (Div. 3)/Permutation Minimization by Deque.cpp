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
#define int long long int
#define S second
#define F first
#define FOR(var, len) for (var = 0; var < len; var++)
#define debug1 cout << "debug1" << '\n'
#define debug2 cout << "debug2" << '\n'
#define debug3 cout << "debug3" << '\n'


// int dr[] = {0,-1,0,1,-1,-1,1,1};
// int dc[] = {-1,0,1,0,-1,1,1,-1};


// Maths Utils
int binExp(int a, int b, int m){int r = 1;while (b){if (b % 2 == 1)r = (r * a) % m;a = (a * a) % m;b = b / 2;}return r;}

// the main catch in this problem is you have to use dequeue  DS as stated else it will give TLE
int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        deque<int> d1;
        int n,x;
        cin>>n;

        for(int i = 0;i<n;i++){
            cin>>x;
            if(i == 0)
                d1.push_front(x);
            else{
                if(x<=*d1.begin())
                    d1.push_front(x);
                else
                    d1.push_back(x);
            }
        }

        for(auto x:d1)
            cout<<x<<" ";
        cout<<'\n';
    }
}
