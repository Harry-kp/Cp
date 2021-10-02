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





// always choose top 2 most socialisable person and arrange a talk
// DS used  - priority queue

int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n,x;
        cin>>n;
        priority_queue<pair<int,int>> pq;
        for(int i = 0;i<n;i++){
            cin>>x;
            if(x>0)
                pq.push({x,i+1});
        }

        vector<pair<int,int>> ans;
        pair<int,int> one,sec;
        while(pq.size()>1){
            one = pq.top();pq.pop();
            sec = pq.top();pq.pop();
            ans.push_back({one.S,sec.S});
            one.F--;
            sec.F--;
            if(one.F)
                pq.push(one);
            if(sec.F)
                pq.push(sec);

        }

        cout<<ans.size()<<'\n';

        for(auto x:ans){
            cout<<x.F<<" "<<x.S<<'\n';
        }
    }
}
