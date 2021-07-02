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

    vector<int> adj[205];
    int color[205];

    bool bip(int s)
    {
        // vis[s] = 1;
        color[s] = 0;

        queue<int> q;
        q.push(s);

        int src, des;
        while (!q.empty())
        {
            src = q.front();
            q.pop();
            for (auto des : adj[src])
            {
                if (color[des] == color[src])
                    return false;
                else if (color[des] == -1){
                    color[des] = 1 - color[src];
                    q.push(des);
                    }
            }
        }
        return true;
    }

    int32_t main()
    {
        fastio;
        while (1)
        {
            int n,m, a, b;
            cin>>n;
            if(n == 0)break;
            cin >> m;

            for (int i = 0; i < m; i++)
            {
                cin >> a >> b;
                adj[a].EB(b);
                adj[b].EB(a);
            }

            // for(auto x:adj){
            //     for(auto y:x)
            //         cout<<y<<" ";
            //         cout<<'\n';}

            memset(color, -1, sizeof(color));
            bool ans = bip(0);

            if (ans)
                cout << "BICOLORABLE.\n";
            else
                cout << "NOT BICOLORABLE.\n";

            for(int i = 0;i<205;i++)
                adj[i].clear();
        }
    }