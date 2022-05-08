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

// Maths Utils
int binExp(int a, int b, int m)
{
    int r = 1;
    while (b)
    {
        if (b % 2 == 1)
            r = (r * a) % m;
        a = (a * a) % m;
        b = b / 2;
    }
    return r;
}

int modinv(int x, int m)
{
    return binExp(x, m - 2, m);
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
        int n;
        cin >> n;
        vector<int> p(n);
        vector<int> leaf(n, 1);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            p[i]--;
            if(p[i]!=i)
                leaf[p[i]] = 0;
            
        }

        vector<vector<int>> ans;

        // the minimum paths will be equal to no. of leaf
        // for each leaf ,

        vector<int> ans_so_far;
        vector<bool> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if(leaf[i])
            {
                int j = i;
                ans_so_far.clear();
                while(!vis[j])
                {
                    ans_so_far.push_back(j + 1);
                    vis[j] = true;
                    j = p[j];
                }
                reverse(ans_so_far.begin(), ans_so_far.end());
                ans.push_back(ans_so_far);
            }
        }

        cout << ans.size() << '\n';
        for (auto path : ans)
        {
            cout << path.size() << '\n';
            for(auto x:path){
                cout << x << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
}
