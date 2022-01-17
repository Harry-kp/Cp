#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define int long long int


bool istotalpal(string s){
    int i = 0;
    while(s[i] == '0')i++;
    int n = s.size();
    bool odd = false,even = false;

    for (int j = i; j+1 < n; j++){
        if(s[j] == s[j+1])
            even = true;
    }
    for (int j = i; j+2 < n; j++){
        if(s[j] == s[j+2])
            odd = true;
    }
        
    return odd&even;
}


int dp[20][11][11][2][2][2][2];

int solve(int pos,int last,int slast,int ev,int od,int t1,int st,string &digit){
    if(pos == digit.size())
        return ev&od;

    if(dp[pos][last][slast][ev][od][t1][st]!=-1)return dp[pos][last][slast][ev][od][t1][st];
    int ans = 0;
    
    int ub = t1?digit[pos]-'0':9;
    //0000101
    for(int j = 0;j<=ub;j++){
        int nst = st|(j>0);
        ans+=solve(pos+1,nst?j:10,nst?last:10,nst&(ev|(last == j)),nst&(od|(slast == j)),t1&(j == ub),nst,digit);
    }

    return  dp[pos][last][slast][ev][od][t1][st] = ans;
}




int32_t main()
{
    
    fastio;
    int t = 1;
    cin >> t;
    string a,b;
    while (t--)
    {
        cin>>a>>b;
        // cout<<a<<b;
        memset(dp,-1,sizeof dp);
        int r = solve(0,10,10,0,0,1,0,b);
        memset(dp,-1,sizeof dp);
        int l = solve(0,10,10,0,0,1,0,a);
        // cout<<r<<" "<<l<<'\n';
        cout<<r-l<<'\n';
    }
}
