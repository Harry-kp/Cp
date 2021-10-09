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

const int N = 100000 + 10;
const int LOG = log2(N) + 2;
int sp[N][LOG],A[N];

int query(int l, int r)
{
    int n = (r-l+1);
    int k = 0;
    while((1<<(k+1))<=n)k++;

    return min(sp[l][k],sp[r-(1<<k)+1][k]);
}

int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int n;
    while (cin>>n)
    {
        for(int i = 0;i<n;i++){
            cin>>A[i];
            sp[i][0] = A[i];
        }
        // preprocessing
        for(int j = 1;j<LOG;j++){
            for(int i = 0;i+(1<<j)-1<n;i++)
                sp[i][j] = min(sp[i][j-1],sp[i + (1<<(j-1))][j-1]);
        }
        int q,l,r;cin>>q;
        for(int i = 0;i<q;i++){
            cin>>l>>r;
            cout<<query(l,r)<<'\n';
        }
    }
}
