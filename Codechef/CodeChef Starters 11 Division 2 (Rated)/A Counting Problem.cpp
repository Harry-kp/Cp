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
#define int long long int
#define S second
#define F first
#define FOR(var, len) for (var = 0; var < len; var++)
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
class ComparisonClass
{
public:
    bool operator()(pair<int, int> const &a, pair<int, int> const &b)
    {
        if (a.F < b.F)
            return true;
        if (a.F == b.F)
            return (a.S > b.S);
        return false;
    }
};

int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    cin >> t;
    priority_queue<pair<int, int>, vector<pair<int, int>>, ComparisonClass> pq;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n], ans[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        int i = 0, cnt = 1;

        while (i < n)
        {
            while (i < 2 * cnt - 1 and i < n)
            {
                pq.push({A[i], i});
                i++;
            }
            ans[pq.top().S] = cnt;
            pq.pop();
            cnt++;
        }

        while (!pq.empty())
        {
            // cout << pq.top().F << " " << pq.top().S << '\n';
            ans[pq.top().S] = cnt;
            pq.pop();
            cnt++;
        }

        for (i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << '\n';
    }
}
