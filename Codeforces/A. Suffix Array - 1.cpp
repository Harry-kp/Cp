#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)
#define PI(a, b) pair<a, b>
#define MP make_pair
#define EB emplace_back
#define MOD 1000000007
#define int long long
#define S second
#define F first
#define endl '\n'
#define FOR(var, len) for (var = 0; var < len; var++)
#define debug1 cout << "debug1" << '\n'
#define debug2 cout << "debug2" << '\n'
#define debug3 cout << "debug3" << '\n'
#define max_l 1000005

vector<int> suffix(string s)
{
    s = s + "$";
    int n = s.size();
    vector<int> eqCls(n), ans(n);
    vector<pair<char, int>> temp(n);

    // base case, sorting characters
    for (int i = 0; i < n; i++)
    {
        temp[i] = {s[i], i};
    }

    sort(temp.begin(), temp.end());

    // create eqvuivalent class
    eqCls[temp[0].S] = 0;
    for (int i = 1; i < n; i++)
    {
        if (temp[i].F == temp[i - 1].F)
        {
            eqCls[temp[i].S] = eqCls[temp[i - 1].S];
        }
        else
        {
            eqCls[temp[i].S] = eqCls[temp[i - 1].S] + 1;
        }
    }

    int k = 0;
    while ((1 << k) < n)
    {
        vector<pair<pair<int, int>, int>> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[i] = {{eqCls[i], eqCls[(i + (1 << k)) % n]}, i};
        }
        sort(temp.begin(), temp.end());

        // update eqvuivalent class
        eqCls[temp[0].S] = 0;
        for (int i = 1; i < n; i++)
        {
            if (temp[i].F == temp[i - 1].F)
            {
                eqCls[temp[i].S] = eqCls[temp[i - 1].S];
            }
            else
            {
                eqCls[temp[i].S] = eqCls[temp[i - 1].S] + 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            ans[i] = temp[i].S;
        }
        k++;
    }
    return ans;
}

int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vector<int> ans(s.size() + 1);
        ans = suffix(s);
        for (int i = 0; i < s.size() + 1; i++)
            cout << ans[i] << " ";
    }
}