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
const int N = (1<<20)+10;
bitset<N> bs;

void solve(){
    int n,q,l,x,ans;
    cin>>n>>q;

    int A[n],sol[q];
    vector<vector<pair<int,int>>> query(n+1);

    for(int i = 0;i<n;i++){
        cin>>A[i];
    }
    for(int i = 0;i<q;i++){
        cin>>l>>x;
        query[l].push_back({x,i});
    }

    vector<int> box;

    ans = 1;
    bs[0] = 1;
    for(int i = 1;i<=n;i++){
        if(bs[A[i-1]] == 1)
            ans = (ans*2)%MOD;
        else{
            box.clear();
            for(int j = 0;j<N;j = bs._Find_next(j)){
                box.EB(A[i-1]^j);
            }

            for(auto it:box)
                bs[it] = 1;
        }

        for(auto it:query[i]){
            if(bs[it.F] == 1)
                sol[it.S] = ans;
            else
                sol[it.S] = 0;
        }
    }

    for(int i = 0;i<q;i++)
        cout<<sol[i]<<'\n';
    // cout<<'\n';

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
        bs.reset();
        solve();
    }
}
