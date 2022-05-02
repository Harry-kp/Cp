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

int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        bool res = true;
        int A[26];
        fill(A,A+26,0);
        int n;cin>>n;
        string s;
        cin>>s;

        if(n%2 == 1){
            cout<<"NO\n";
            continue;
        }

        // else even
        string ans = s;
        for(auto x:s)
            A[x-'a']++;
        
        priority_queue<pair<int,int>> pq;
        for(int i = 0;i<26;i++)
            if(A[i]>0){
                pq.push({A[i],i});
        }

        int l = 0;
        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();
            if(pq.empty()){
                if(u.first>1)
                    res = false;
                    break;
            }
            
            auto v = pq.top();
            pq.pop();

            ans[l] = char('a' + u.second);
            ans[n-l-1] = char('a' + v.second);
            l++;
            if(u.first-1>0)
                pq.push({u.first-1,u.second});
            if(v.first-1>0)
                pq.push({v.first-1,v.second});
        }
        if(res)
            {cout<<"YES\n";
            cout<<ans<<'\n';}
        else
            cout<<"NO\n";
        // cout<<((res)?("YES":"NO"))<<'\n';

    }
}

