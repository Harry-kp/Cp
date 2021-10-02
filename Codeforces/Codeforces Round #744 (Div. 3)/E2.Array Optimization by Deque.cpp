#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)
#define MP make_pair
#define EB emplace_back
#define MOD 1000000007
// #define int long long int
#define S second
#define F first
#define debug1 cout << "debug1" << '\n'
#define debug2 cout << "debug2" << '\n'
#define debug3 cout << "debug3" << '\n'


// int dr[] = {0,-1,0,1,-1,-1,1,1};
// int dc[] = {-1,0,1,0,-1,1,1,-1};


// Maths Utils
int binExp(int a, int b, int m){int r = 1;while (b){if (b % 2 == 1)r = (r * a) % m;a = (a * a) % m;b = b / 2;}return r;}

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
typedef tree<
pair<int,int>,
null_type,
less<pair<int,int>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;


int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        long long int ans = 0;
        cin>>n;
        int A[n];
        ordered_multiset s1;
        for(int i = 0;i<n;i++){
            cin>>A[i];

            int less = s1.order_of_key({A[i],0});
            int great = i - s1.order_of_key({A[i],n});

            ans += min(less,great);
            s1.insert({A[i],i});

        }
        cout<<ans<<'\n';
        
    }
}
