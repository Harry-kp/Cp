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
#define ii pair<int, int>

int visited[1004][1004];
int pre[1004][1004];
char grid[1004][1004];

int row[] = {-1, 0, 1, 0};
int col[] = {0, -1, 0, 1};

string directions = "ULDR";

void bfs(ii u, int n, int m)
{
    visited[u.F][u.S] = true;
    list<ii> que;
    que.push_back(u);

    while (!que.empty())
    {
        ii u = que.front();
        que.pop_front();

        for (int i = 0; i < 4; i++)
        {
            if (u.F + row[i] < 0 or u.F + row[i] >= n or u.S + col[i] < 0 or u.S + col[i] >= m)
                continue;
            if (grid[u.F + row[i]][u.S + col[i]] == '#' or visited[u.F + row[i]][u.S + col[i]])
                continue;
            visited[u.F + row[i]][u.S + col[i]] = true;
            pre[u.F + row[i]][u.S + col[i]] = i;
            que.push_back(MP(u.F + row[i], u.S + col[i]));
        }
    }
}

int32_t main()
{
    fastio;

    memset(visited, false, sizeof(visited));
    int n, m, i;
    ii src, dest;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 'A')
                src = MP(i, j);
            if (grid[i][j] == 'B')
                dest = MP(i, j);
        }
    }
    bfs(src, n, m);

    if (visited[dest.F][dest.S])
    {
        cout << "YES\n";
        string ans = "";
        while (src != dest)
        {
            ans += directions[pre[dest.F][dest.S]];
            dest = MP(dest.F - row[pre[dest.F][dest.S]], dest.S - col[pre[dest.F][dest.S]]);
        }
        cout << ans.size() << '\n';
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
    else
    {
        cout << "NO\n";
    }
}