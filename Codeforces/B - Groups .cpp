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
        cin>>n;

        int A[n][5];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<5;j++){
                cin>>A[i][j];
            }
        }
        bool ok = false;
        int l,r,h = n/2,m;
        for(int j = 0;j<4;j++){
            for(int k = j+1;k<5;k++){
                l = 0;
                r = 0;
                m = 0;
                for(int i = 0;i<n;i++){
                    if(A[i][j] == 1 and A[i][k] == 1){
                        m++;
                    }
                    else if(A[i][j] == 1)
                        l++;
                    else if(A[i][k] == 1)
                        r++;
                }
                if(l>h or r>h)
                    continue;
                else{
                    if(h-l + h-r  == m)
                        ok = true;
                }
            }
        }
        cout<<(ok?"YES":"NO")<<'\n';
    }
}
