#include <bits/stdc++.h>
using namespace std;

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
    return ans;
}

int binary(int l, int r, vector<int> &ans, string &key, string &s)
{
    int mid = (l + r) / 2;
    if (l > r)
        return 0;

    if (s.substr(ans[mid], key.size()) == key)
        return 1;

    if (s.substr(ans[mid], key.size()) > key)
        return binary(l, mid - 1, ans, key, s);

    return binary(mid + 1, r, ans, key, s);
}

int32_t main()
{
    string s, temp;
    cin >> s;
    int k;
    cin >> k;
    vector<int> ans = suffix(s);

    for (int i = 0; i < k; i++)
    {
        cin >> temp;
        if (binary(0, s.size(), ans, temp, s))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}