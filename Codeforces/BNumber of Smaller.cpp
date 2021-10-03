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

void solve(){
    int n1,n2;
    cin>>n1>>n2;
    int A[n1],B[n2];
    for(int i = 0;i<n1;i++)cin>>A[i];
    for (int i = 0; i < n2; i++)
        cin >> B[i];

    int i = 0,j = 0;
    while(j<n2){
        while(i<n1 and A[i]<B[j])
            i++;
        B[j] = i;
        j++;
    }
    for (int i = 0; i < n2; i++)
    cout<<B[i]<<" ";
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
