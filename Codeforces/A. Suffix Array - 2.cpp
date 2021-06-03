#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<pair<pair<int, int>, int>> &temp, int n, int key)
{
    vector<int> count(n, 0), cnt(n, 0);
    vector<pair<pair<int, int>, int>> output(n);

    for (int i = 0; i < n; i++)
    {
        if (key == 1)
        {
            count[temp[i].first.first]++;
        }
        else
        {
            count[temp[i].first.second]++;
        }
    }

    cnt = count;
    for (int i = 1; i < n; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        if (key == 1)
        {
            output[count[temp[i].first.first] - cnt[temp[i].first.first]] = temp[i];
            cnt[temp[i].first.first]--;
        }
        else
        {
            output[count[temp[i].first.second] - cnt[temp[i].first.second]] = temp[i];
            cnt[temp[i].first.second]--;
        }
    }
    temp = output;
}


vector<int> suffix(string s)
{
    s = s + "$";
    int n = s.size();

    vector<int> c(n), a(n);
    vector<pair<char, int>> temp(n);

    for (int i = 0; i < n; i++)
        temp[i] = {s[i], i};
    sort(temp.begin(), temp.end());

    for (int i = 0; i < n; i++)
        a[i] = temp[i].second;

    for (int i = 1; i < n; i++)
    {
        if (temp[i].first == temp[i - 1].first)
            c[a[i]] = c[a[i - 1]];
        else
            c[a[i]] = c[a[i - 1]] + 1;
    }

    {
        int k = 0;
        vector<pair<pair<int, int>, int>> temp(n);
        while ((1 << k) < n)
        {
            for (int i = 0; i < n; i++)
            {
                temp[i] = {{c[i], c[(i + (1 << k)) % n]}, i}; //() around 1<<k is important
            }

            countingSort(temp, n, 2);
            countingSort(temp, n, 1);
            for (int i = 0; i < n; i++)
                a[i] = temp[i].second;

            for (int i = 1; i < n; i++)
            {
                if (temp[i].first == temp[i - 1].first)
                    c[a[i]] = c[a[i - 1]];
                else
                    c[a[i]] = c[a[i - 1]] + 1;
            }

            k++;
        }
    }
    return a;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    vector<int> ans(s.size() + 1);
    ans = suffix(s);
    for (auto x : ans)
        cout << x << " ";
}