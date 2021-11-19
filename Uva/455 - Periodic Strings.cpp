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

int lsp(string pat){
    int n = pat.size();
    vector<int> pie(n,0);

    int j = 0;
    pie[0] = 0;
    for(int i = 1;i<n;i++){
        while(j>=0 and pat[i]!=pat[j]){
            if(j>=1)j = pie[j-1];
            else j = -1;
        }

        // increment prefix count by 1
        j++;
        pie[i] = j;
    }
    return j;
}


void solve(){
    string s;
    cin>>s;
    int n = s.size();
    int pie = lsp(s);
    
    if(n%(n-pie))
        cout<<n<<'\n';
    else
        cout<<n-pie<<'\n';
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
        if(t)cout<<"\n";
    }
}
