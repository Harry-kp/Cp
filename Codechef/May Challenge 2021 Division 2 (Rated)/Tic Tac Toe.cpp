// Same as spoj tic-tac-toe-1

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

using namespace std;

char tic[3][3];

bool row_wise(char winner)
{
    for (int i = 0; i < 3; i++)
    {
        if (tic[i][0] == winner && tic[i][1] == winner && tic[i][2] == winner)
        {
            return true;
        }
    }
    return false;
}
bool col_wise(char winner)
{
    for (int i = 0; i < 3; i++)
    {
        if (tic[0][i] == winner && tic[1][i] == winner && tic[2][i] == winner)
        {
            return true;
        }
    }
    return false;
}

bool dig_wise(char winner)
{
    if (tic[0][0] == winner && tic[1][1] == winner && tic[2][2] == winner)
    {
        return true;
    }
    if (tic[0][2] == winner && tic[1][1] == winner && tic[2][0] == winner)
    {
        return true;
    }
    return false;
}

void solve()
{
    int i, j, cx = 0, co = 0,cu = 0;
    bool reachable = true,wx,wo;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            cin >> tic[i][j];
            if(tic[i][j] == 'X')
                cx++;
            if (tic[i][j] == 'O')
                co++;
            if (tic[i][j] == '_')
                cu++;
        }


    if ((cx - co) > 1)
    {
        reachable = false;
    }

    if (co > cx)
    {
        reachable = false;
    }

    wx = (row_wise('X') || col_wise('X') || dig_wise('X'));
    if (wx)
    {
        if ((cx - co) != 1)
        {
            reachable = false;
        }
    }

    wo = (row_wise('O') || col_wise('O') || dig_wise('O'));
    if (wo)
    {
        if ((cx - co) != 0)
        {
            reachable = false;
        }
    }
    if (wo && wx)
    {
        reachable = false;
    }
    // cout<<wo<<" "<<wx<<" "<<reachable<<" "<<co<<" "<<cx<<'\n';
    if (reachable and ((!wo and !wx and !cu) or (wx or wo)))
    {
        cout<<"1\n";
    }
    else if(!reachable)
    {
        cout<<"3\n";
    }
    else
    {
        printf("2\n");
    }
}

int32_t main()
{
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
}
