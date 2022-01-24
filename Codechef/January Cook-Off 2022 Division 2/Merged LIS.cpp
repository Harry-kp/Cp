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


int lis(int n,vector<int> a){
    
    multiset<int> S;
    multiset<int>::iterator it;
    for (int x : a)
    {
        S.insert(x);
        it = S.upper_bound(x);
        if (it != S.end()) S.erase(it);
    }
    
    return S.size();
}


void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> A(n),B(m);

    for(int i = 0;i<n;i++)
        cin>>A[i];
    for(int i = 0;i<m;i++)
        cin>>B[i];
    
    cout<< lis(n,A) + lis(m,B)<<'\n';
    
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
    }
}




