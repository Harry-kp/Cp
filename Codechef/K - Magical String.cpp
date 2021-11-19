#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define EB emplace_back
#define MOD 1000000007
// #define int long long int
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

// struct segtree
// {
//     int size;
//     vector<vector<int>> tree;

//     void init(int n)
//     {
//         size = 1;
//         while (size < n)
//         {
//             size = size * 2;
//         }
//         tree.assign(2 * size, vector<int>(26,0));
//     }

//     void update(int ind, int val)
//     {
//         update(ind, val, 0, 0, size);
//     }

//     void update(int ind, int val, int x, int lx, int rx)
//     {
//         if (rx - lx == 1)
//         {
//             tree[x][val] += 1;
//             return;
//         }

//         int m = (rx + lx) / 2;
//         if (ind < m)
//         {
//             update(ind, val, 2 * x + 1, lx, m);
//         }
//         else
//         {
//             update(ind, val, 2 * x + 2, m, rx);
//         }
//         for(int i = 0;i<26;i++)
//             tree[x][i] = tree[2 * x + 1][i] + tree[2 * x + 2][i];
//     }

//     vector<int> query(int l, int r)
//     {
//         return query(l, r, 0, 0, size);
//     }

//     vector<int> query(int l, int r, int x, int lx, int rx)
//     {
//         if (r <= lx or l >= rx)
//             return vector<int>(26);
//         if (lx >= l and r >= rx)
//             return tree[x];

//         int m = (lx + rx) / 2;
//         vector<int> left = query(l, r, 2 * x + 1, lx, m);
//         vector<int> right = query(l, r, 2 * x + 2, m, rx);
//         vector<int> ans(26);
//         for(int i = 0;i<26;i++)
//             ans[i] = left[i]+right[i];
//         return ans ;
//     }
// };

vector<int> query(int l,int r,vector<vector<int>>&pre){
    vector<int> ans(26);

    for(int i = 0;i<26;i++){
        ans[i] = (pre[r][i]-((l == 0)?0:pre[l-1][i]));
    }
    return ans;
}

// segment tree here is an overkill but i used segment tree to master it.
// Alternatively we can use some sort of prefix array type for alphabets count as there are offline queries only

// UPDATE :- Segment tree will give TLE.
// Trying prefix array approach
int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n,l,r,k;cin>>n;
        string s;
        cin>>s;
        int q;cin>>q;
        vector<vector<int>> prefix(n,vector<int>(26));

        prefix[0][s[0]-'A']++;
        for(int i = 1;i<n;i++){
            for(int j = 0;j<26;j++)
                prefix[i][j] += prefix[i-1][j];
            prefix[i][s[i]-'A']++;
        }


        for(int i = 0;i<q;i++){
            cin>>l>>r>>k;
            r--;l--;
            if(r-l+1<k){
                cout<<"No\n";
                continue;
            }
            vector<int> ans;
            ans = query(l,r,prefix);
            int mx = *max_element(ans.begin(),ans.end());
            if(mx>k){
                cout<<"No\n";
                continue;
            }

            string out = "";
            for(int i = 25;i>=0;i--){
                for(int j = 0;j<ans[i];j++)
                    out+=char(i+'A');
            }
            if(mx == k){
                cout<<"Yes\n";
                cout<<out<<'\n';
                continue;
            }

            int x = out.size();
            string f = "",l = "";
            for(int i = 0;i<x;i++){
                if(i<k)
                    l = l+out[x-i-1];
                else
                    f = out[x-i-1]+f;
            }
            cout<<"Yes\n";
            cout<<f+l<<'\n';
        }
    }
}
