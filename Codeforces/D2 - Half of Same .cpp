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


int solve(){
    int n;cin>>n;
    int A[n];
    map<int,int> m1;
    for(int i = 0;i<n;i++){
        cin>>A[i];
        m1[A[i]]++;
    }

    // base case when count of any number is at least n/2
    for(auto x:m1){
        if(x.S*2>=n){
            return -1;
        }
    }


    // the value of k will be divisor of (A[i] - A[j]) for any i,j.
    // Hence, first find all the options  for k , i.e for all i,j pairs find divisors of abs(A[i],A[j])

    int ans = -1;
    set<int> ops;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            int x = abs(A[i] - A[j]);

            // count divisors
            for(int i = 1;i*i<=x;i++){
                if(x%i == 0){
                    ops.insert(i);
                    ops.insert(x/i);
                }
            }
        }
    }

    for(auto x:ops){
        m1.clear();
        for(int i = 0;i<n;i++){
            int tmp = A[i] % x;
            tmp+=2*x;tmp%=x;
            m1[tmp]++;
        }

        for(auto y:m1){
            if(2*y.S>=n)
                ans = max(ans,x);
        }
    }
    return ans;
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
        cout<<solve()<<'\n';
    }
}
