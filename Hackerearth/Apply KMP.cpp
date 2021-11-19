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

vector<int> lsp(string pat){
    int n = pat.size();
    vector<int> pie(n,0);
    int j = 0;
    pie[0] = 0;
    for(int i = 1;i<n;i++){
        while(j>0 and pat[i]!=pat[j])j = pie[j-1];
        if(pat[i] == pat[j])j++;
        pie[i] = j;
    }
    return pie;
}

int kmp(string s,string p){
    int sz = s.size();
    int psz = p.size();
    int ans = 0;
    vector<int> pie = lsp(p);
    int j = 0;
    for(int i = 0;i<sz;i++){
        while(j>0 and s[i]!=p[j])j = pie[j-1];
        if(s[i] == p[j])j++;
        if(j == psz)
            ans++;
    }
    return ans;
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
        string s1,s2;
        cin>>s1>>s2;
        cout<<kmp(s2,s1)<<'\n';
    }
}
