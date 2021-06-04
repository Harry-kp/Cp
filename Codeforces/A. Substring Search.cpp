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

int lb(int l, int r, vector<int> &ans, string &key, string &s)
{
    while(r>l){
    int mid = (l + r) / 2;
        if(key<=s.substr(ans[mid],key.size())){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    return l;
}

int ub(int l, int r, vector<int> &ans, string &key, string &s)
{
    while (r > l)
    {
    int mid = (l + r) / 2;
        if (key>=s.substr(ans[mid], key.size()))
        {
            l = mid+1;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}

int32_t main()
{
    string s, temp;
    cin >> s;
    int k;
    cin >> k;
    vector<int> ans = suffix(s);
    
    // for(auto x:ans)cout<<s.substr(x,s.size())<<'\n';
    for (int i = 0; i < k; i++)
    {   int l,r;
        cin >> temp;
        l = lb(0,s.size()+1,ans,temp,s);
        r = ub(0, s.size()+1, ans, temp, s);

        cout<<r-l<<'\n';
        
    }
}