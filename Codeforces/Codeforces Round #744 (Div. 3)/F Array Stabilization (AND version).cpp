#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define EB emplace_back
#define MOD 1000000007
#define int long long int
#define S second
#define F first
#define debug1 cout << "debug1" << '\n'
#define debug2 cout << "debug2" << '\n'
#define debug3 cout << "debug3" << '\n'


// int dr[] = {0,-1,0,1,-1,-1,1,1};
// int dc[] = {-1,0,1,0,-1,1,1,-1};


// Maths Utils
int binExp(int a, int b, int m){int r = 1;while (b){if (b % 2 == 1)r = (r * a) % m;a = (a * a) % m;b = b / 2;}return r;}

// THIS QUESTION IS COMPLICATED CASE OF MAKING A BINARY CHAIN INTO ZEROES PROBLEM WHILE TAKING AND OF ADJACENT INDEX
// FIRST WE EXTRACT EACH SINGLE CHAIN AND SOLVE THEM INDIVIDUALLY , IF ANY CHAIN CONTAINS ALL 1,THEN ANS IS 1
// ELSE ANS IS MAXIMUM ANS OF ALL CHAINS

// THIS FUN EVALUATES A SINGLE CHAIN
int solve_ring(vector<int> A){
    bool flag = true;
    int mx = -1;
    int tmp = 0,n = A.size();
    for(int i = 0;i<2*n;i++){
        if(A[i%n] == 0)flag = false;
        if(A[i%n] == 1)
            tmp++;
        else{
            mx = max(tmp,mx);
            tmp = 0;
        }
    }
    mx = max(tmp,mx);
    return flag?INT_MAX:mx;
}


int32_t main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n,d;
        cin>>n>>d;
        int A[n];
        bool flag = true;
        for(int i = 0;i<n;i++){
            cin>>A[i];
            if(!A[i])
                flag = false;
        }
        if(flag)
        {
            cout<<-1<<'\n';
            continue;
        }
        

        vector<int> used(n,false);
        vector<int> tmp;
        int j,mx=-1;
        for(int i = 0;i<d;i++){
            int curr = i;
            if(used[curr])continue;

            while(!used[curr]){
                tmp.EB(A[curr]);
                used[curr] = true;
                curr = (curr + d)%n;
            }
            mx = max(mx,solve_ring(tmp));
            tmp.clear();
        }
        if(mx == INT_MAX)
            cout<<-1<<'\n';
        else
            cout<<mx<<'\n';
    }
}
