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

void counting_sort(vector<int> &ans, vector<int> &cls)
{
    // sort ans taking cls as key
    int n = ans.size();
    vector<int> count(n, 0), ans_new(n);

    for (int i = 0; i < n; i++)
        count[cls[i]]++;

    vector<int> pos(n);

    pos[0] = 0;
    for (int i = 1; i < n; i++)
        pos[i] = pos[i - 1] + count[i - 1];

    for (auto x : ans)
    {
        int key = cls[x];
        ans_new[pos[key]] = x;
        pos[key]++;
    }

    ans = ans_new;
}

vector<int> suffix(string s)
{
    s = s + "$";
    int n = s.size();
    vector<int> ans(n), cls(n);

    // Base case
    vector<pair<char, int>> temp(n);
    for (int i = 0; i < n; i++)
    {
        temp[i] = {s[i], i};
    }
    sort(temp.begin(), temp.end());
    // Update intermediate result
    for (int i = 0; i < n; i++)
        ans[i] = temp[i].second;

    // Update intermediate equivalence class
    cls[ans[0]] = 0;
    for (int i = 1; i < n; i++)
    {
        if (temp[i - 1].first == temp[i].first)
            cls[ans[i]] = cls[ans[i - 1]];
        else
            cls[ans[i]] = cls[ans[i - 1]] + 1;
    }

    // Inductive cases
    {
        int k = 0;
        while (n > (1 << k))
        {
            // Append 2**k string part to left side, which make it right 2**k part sorted by default
            for (int i = 0; i < n; i++)
                ans[i] = (ans[i] - (1 << k) + n) % n;
            counting_sort(ans, cls);
            // sort(ans.begin(),ans.end(),[&](int a,int b){return cls[a]<cls[b];});

            vector<int> cls_new(n);
            cls_new[ans[0]] = 0;
            for (int i = 1; i < n; i++)
            {
                pair<int, int> now = {cls[ans[i]], cls[(ans[i] + (1 << k)) % n]};
                pair<int, int> prev = {cls[ans[i - 1]], cls[(ans[i - 1] + (1 << k)) % n]};

                if (now == prev)
                {
                    cls_new[ans[i]] = cls_new[ans[i - 1]];
                }
                else
                    cls_new[ans[i]] = cls_new[ans[i - 1]] + 1;
            }
            cls = cls_new;
            k++;
        }
    }
    // for (auto x : ans)
    //     cout << x << " ";
    // cout << '\n';
    // for (auto x : cls)
    //     cout << x << " ";
    // return ans;
    return ans;
}

vector<int> LCP(vector<int> ans, string s)
{
    int n = ans.size();
    vector<int> cls(n);

    for (int i = 0; i < n; i++)
    {
        cls[ans[i]] = i;
    }

    int k = 0;
    vector<int> lcp(n);

    for (int i = 0; i < n - 1; i++)
    {
        int pi = cls[i];
        int j = ans[pi - 1];

        while (s[i + k] == s[j + k])
            k++;

        lcp[i] = k;
        k = max(0ll, k - 1);
    }
    return lcp;
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
        vector<int> ans = suffix(s);

        vector<int> lcp = LCP(ans, s);

        int out = 0;

        for (int i = 0; i < ans.size(); i++)
        {
            out += (s.size() - ans[i] - lcp[i]);
        }
        cout << out;
    }
}